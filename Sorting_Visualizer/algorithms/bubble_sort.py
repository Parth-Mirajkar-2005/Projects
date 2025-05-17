def bubble_sort(arr):
    """Bubble Sort algorithm that tracks swaps for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, indices).
              indices is a list of (i, j) tuples for swaps.
    """
    steps = [(arr.copy(), [])]  # Start with the initial array
    array = arr.copy()
    n = len(array)
    
    # Go through each pass
    for i in range(n):
        swaps_in_pass = []  # Track swaps in this pass
        for j in range(0, n - i - 1):
            if array[j] > array[j + 1]:
                # Swap the elements
                array[j], array[j + 1] = array[j + 1], array[j]
                swaps_in_pass.append((j, j + 1))  # Record the swap
        # If there were swaps, add the step
        if swaps_in_pass:
            steps.append((array.copy(), swaps_in_pass))
    
    return steps