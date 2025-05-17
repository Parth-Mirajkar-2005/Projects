def selection_sort(arr):
    """Selection Sort algorithm that tracks swaps for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, indices).
    """
    steps = [(arr.copy(), [])]  # Start with the initial array
    array = arr.copy()
    n = len(array)
    
    # Go through each position
    for i in range(n):
        min_idx = i  # Find the minimum element in the unsorted portion
        for j in range(i + 1, n):
            if array[j] < array[min_idx]:
                min_idx = j
        # If the minimum is not at position i, swap
        if min_idx != i:
            array[i], array[min_idx] = array[min_idx], array[i]
            steps.append((array.copy(), [(i, min_idx)]))  # Record the swap
    
    return steps