def counting_sort(arr):
    """Counting Sort algorithm that tracks updates for visualization.

    Args:
        arr (list): The list to sort (assumes non-negative integers).

    Returns:
        list: List of steps, where each step is a tuple of (array_state, indices).
              indices is a list of (i, i) tuples for updates.
    """
    steps = [(arr.copy(), [])]  # Start with the initial array
    array = arr.copy()
    n = len(array)
    
    # Step 1: Find the maximum value to determine the size of the count array
    if not array:
        return steps
    max_val = max(array)
    min_val = min(array)
    range_of_values = max_val - min_val + 1
    
    # Step 2: Create a count array to store the frequency of each value
    count = [0] * range_of_values
    for num in array:
        count[num - min_val] += 1
    
    # Step 3: Compute cumulative counts to determine final positions
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    
    # Step 4: Build the output array by placing elements in their final positions
    output = [0] * n
    for i in range(n - 1, -1, -1):
        val = array[i]
        count[val - min_val] -= 1
        output[count[val - min_val]] = val
    
    # Step 5: Update the original array in-place with steps
    for i in range(n):
        if array[i] != output[i]:
            array[i] = output[i]
            # Record the update as a "swap" at the same index
            steps.append((array.copy(), [(i, i)]))
    
    return steps