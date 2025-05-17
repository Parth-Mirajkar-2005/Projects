def merge_sort(arr):
    """Merge Sort algorithm that tracks swaps for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, indices).
    """
    steps = [(arr.copy(), [])]  # Start with the initial array
    array = arr.copy()
    
    def _merge_sort(low, high):
        if low < high:
            mid = (low + high) // 2
            _merge_sort(low, mid)  # Sort left half
            _merge_sort(mid + 1, high)  # Sort right half
            _merge(low, mid, high)  # Merge the two halves
    
    def _merge(low, mid, high):
        left = array[low:mid + 1].copy()
        right = array[mid + 1:high + 1].copy()
        i = j = 0
        k = low
        swaps = []  # Track swaps during merging
        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                if array[k] != left[i]:
                    array[k] = left[i]
                    swaps.append((k, k))  # Record as a swap (same index for simplicity)
                i += 1
            else:
                if array[k] != right[j]:
                    array[k] = right[j]
                    swaps.append((k, k))  # Record as a swap
                j += 1
            k += 1
        # Add remaining elements from left
        while i < len(left):
            if array[k] != left[i]:
                array[k] = left[i]
                swaps.append((k, k))
            i += 1
            k += 1
        # Add remaining elements from right
        while j < len(right):
            if array[k] != right[j]:
                array[k] = right[j]
                swaps.append((k, k))
            j += 1
            k += 1
        if swaps:
            steps.append((array.copy(), swaps))
    
    _merge_sort(0, len(array) - 1)
    return steps