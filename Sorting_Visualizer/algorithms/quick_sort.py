def quick_sort(arr):
    """Quick Sort algorithm that returns a list of intermediate steps with minimal memory usage.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, swapped_indices).
    """
    steps = [(arr.copy(), [])]  # Initial state with no swaps
    array = arr.copy()  # Working copy of the array
    
    def _quick_sort(array, low, high, steps):
        if low < high:
            # Partition the array and get the pivot index
            pivot_idx = _partition(array, low, high, steps)
            
            # Recursively sort the left and right subarrays
            _quick_sort(array, low, pivot_idx - 1, steps)
            _quick_sort(array, pivot_idx + 1, high, steps)
    
    def _partition(array, low, high, steps):
        pivot = array[high]
        i = low - 1
        
        for j in range(low, high):
            if array[j] <= pivot:
                i += 1
                if i != j:  # Only record a step if a swap occurs
                    array[i], array[j] = array[j], array[i]
                    steps.append((array.copy(), [(i, j)]))
        
        # Place the pivot in its correct position
        if i + 1 != high:
            array[i + 1], array[high] = array[high], array[i + 1]
            steps.append((array.copy(), [(i + 1, high)]))
        return i + 1
    
    _quick_sort(array, 0, len(array) - 1, steps)
    return steps