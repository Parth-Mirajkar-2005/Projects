def insertion_sort(arr):
    """Insertion Sort algorithm that returns a list of intermediate steps.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, swapped_indices).
    """
    steps = [(arr.copy(), [])]  # Initial state with no swaps
    n = len(arr)
    array = arr.copy()
    
    for i in range(1, n):
        key = array[i]
        j = i - 1
        current_swaps = []
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            current_swaps.append((j, j + 1))
            j -= 1
        array[j + 1] = key
        if current_swaps:
            steps.append((array.copy(), current_swaps))
    
    return steps