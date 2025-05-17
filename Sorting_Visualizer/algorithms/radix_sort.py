def radix_sort(arr):
    """Radix Sort algorithm with step tracking for visualization.

    Args:
        arr (list): The list to sort (non-negative integers).

    Returns:
        list: List of steps, where each step is a tuple (array_state, indices).
    """
    steps = []
    # Initial step: the original array
    steps.append((arr.copy(), []))
    
    # Handle empty array or array with negative numbers
    if not arr:
        return steps
    if any(x < 0 for x in arr):
        raise ValueError("Radix Sort requires non-negative integers")
    
    # Find the maximum number to determine the number of digits
    max_num = max(arr)
    if max_num == 0:
        return steps  # If max is 0, array is already "sorted"
    
    # Number of digits in the maximum number
    exp = 1  # Start with the least significant digit (1's place)
    
    # Process each digit
    while max_num // exp > 0:
        # Use counting sort for the current digit
        n = len(arr)
        output = [0] * n  # Output array for the current digit
        count = [0] * 10  # Count array for digits 0-9
        
        # Count occurrences of each digit
        for i in range(n):
            digit = (arr[i] // exp) % 10
            count[digit] += 1
        
        # Compute cumulative count
        for i in range(1, 10):
            count[i] += count[i - 1]
        
        # Build the output array (process in reverse to maintain stability)
        indices = []  # To track "swaps" for visualization
        for i in range(n - 1, -1, -1):
            digit = (arr[i] // exp) % 10
            count[digit] -= 1
            output[count[digit]] = arr[i]
            # Record the movement as a "swap" between the original position and the new position
            if i != count[digit]:
                indices.append((i, count[digit]))
        
        # Copy the output array back to arr
        for i in range(n):
            arr[i] = output[i]
        
        # Record the step after processing this digit
        if indices:
            steps.append((arr.copy(), indices))
        
        # Move to the next digit
        exp *= 10
    
    return steps