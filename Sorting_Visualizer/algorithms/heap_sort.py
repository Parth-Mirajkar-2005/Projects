def heap_sort(arr):
    """Heap Sort algorithm that returns a list of intermediate steps.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, swapped_indices).
    """
    steps = [(arr.copy(), [])]  # Initial state with no swaps
    array = arr.copy()
    n = len(array)
    
    def heapify(array, n, i, steps):
        largest = i
        left = 2 * i + 1
        right = 2 * i + 2
        current_swaps = []
        
        if left < n and array[left] > array[largest]:
            largest = left
        
        if right < n and array[right] > array[largest]:
            largest = right
        
        if largest != i:
            array[i], array[largest] = array[largest], array[i]
            current_swaps.append((i, largest))
            steps.append((array.copy(), current_swaps))
            heapify(array, n, largest, steps)
    
    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(array, n, i, steps)
    
    # Extract elements from heap
    for i in range(n - 1, 0, -1):
        array[0], array[i] = array[i], array[0]
        steps.append((array.copy(), [(0, i)]))
        heapify(array, i, 0, steps)
    
    return steps