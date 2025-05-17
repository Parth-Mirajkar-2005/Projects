def gnome_sort(arr):
    """Gnome Sort algorithm with step tracking for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple (array_state, indices).
    """
    steps = []
    # Initial step: the original array
    steps.append((arr.copy(), []))
    
    n = len(arr)
    index = 0
    
    while index < n:
        # If at the start or the current element is greater than or equal to the previous
        if index == 0 or arr[index] >= arr[index - 1]:
            index += 1
        else:
            # Swap with the previous element and move back
            swaps = [(index, index - 1)]
            arr[index], arr[index - 1] = arr[index - 1], arr[index]
            steps.append((arr.copy(), swaps))
            index -= 1
    
    return steps