def comb_sort(arr):
    """Comb Sort algorithm with step tracking for visualization.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple (array_state, indices).
    """
    steps = []
    # Initial step: the original array
    steps.append((arr.copy(), []))
    
    n = len(arr)
    # Start with a large gap
    gap = n
    shrink = 1.3  # Shrink factor
    swapped = True
    
    while gap > 1 or swapped:
        # Update the gap
        gap = max(1, int(gap / shrink))
        swapped = False
        swaps = []
        
        # Compare elements with the current gap
        for i in range(n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swaps.append((i, i + gap))
                swapped = True
        
        if swaps:
            steps.append((arr.copy(), swaps))
    
    return steps