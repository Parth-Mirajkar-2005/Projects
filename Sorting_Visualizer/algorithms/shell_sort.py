def shell_sort(arr):
    """Shell Sort algorithm with step tracking for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple (array_state, indices).
    """
    steps = []
    # Initial step: the original array
    steps.append((arr.copy(), []))
    
    n = len(arr)
    # Start with a large gap and reduce it
    gap = n // 2
    
    while gap > 0:
        # Perform insertion sort for elements at the current gap
        for i in range(gap, n):
            temp = arr[i]
            j = i
            swaps = []
            # Shift earlier gap-sorted elements up until the correct location for arr[i] is found
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                swaps.append((j, j - gap))
                j -= gap
            arr[j] = temp
            # Record the step if there were any swaps
            if swaps:
                steps.append((arr.copy(), swaps))
        # Reduce the gap for the next iteration
        gap //= 2
    
    return steps