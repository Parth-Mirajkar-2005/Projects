def cocktail_shaker_sort(arr):
    """Cocktail Shaker Sort algorithm with step tracking for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple (array_state, indices).
    """
    steps = []
    # Initial step: the original array
    steps.append((arr.copy(), []))
    
    n = len(arr)
    swapped = True
    start = 0
    end = n - 1
    
    while swapped:
        # Reset swapped flag
        swapped = False
        # Forward pass (left to right)
        forward_swaps = []
        for i in range(start, end):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                forward_swaps.append((i, i + 1))
                swapped = True
        if forward_swaps:
            steps.append((arr.copy(), forward_swaps))
        
        if not swapped:
            break
        
        # Decrease end because the largest element is now at the end
        end -= 1
        swapped = False
        # Backward pass (right to left)
        backward_swaps = []
        for i in range(end - 1, start - 1, -1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                backward_swaps.append((i, i + 1))
                swapped = True
        if backward_swaps:
            steps.append((arr.copy(), backward_swaps))
        
        # Increase start because the smallest element is now at the start
        start += 1
    
    return steps