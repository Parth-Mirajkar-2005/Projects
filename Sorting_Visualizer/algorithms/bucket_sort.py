def bucket_sort(arr):
    """Bucket Sort algorithm that returns a list of intermediate steps.

    Args:
        arr (list): The list to sort.

    Returns:
        list: List of steps, where each step is a tuple of (array_state, swapped_indices).
    """
    steps = [(arr.copy(), [])]  # Initial state with no swaps
    array = arr.copy()
    n = len(array)
    
    if n == 0:
        return steps
    
    # Find the range of values
    min_val = min(array)
    max_val = max(array)
    if min_val == max_val:
        return steps
    
    # Create buckets
    bucket_count = n
    bucket_range = (max_val - min_val) / bucket_count
    buckets = [[] for _ in range(bucket_count)]
    
    # Distribute elements into buckets with steps
    for i, num in enumerate(array):
        idx = min(int((num - min_val) / bucket_range), bucket_count - 1)
        buckets[idx].append(num)
        array[i] = 0
        steps.append((array.copy(), [(i, i)]))
    
    # Sort each bucket using insertion sort and track steps
    k = 0
    for bucket_idx, bucket in enumerate(buckets):
        for i in range(1, len(bucket)):
            key = bucket[i]
            j = i - 1
            current_swaps = []
            while j >= 0 and bucket[j] > key:
                bucket[j + 1] = bucket[j]
                current_swaps.append((k + j, k + j + 1))
                j -= 1
            bucket[j + 1] = key
            if current_swaps:
                for idx in range(len(bucket)):
                    array[k + idx] = bucket[idx]
                steps.append((array.copy(), current_swaps))
        for idx, val in enumerate(bucket):
            array[k + idx] = val
            steps.append((array.copy(), [(k + idx, k + idx)]))
        k += len(bucket)
    
    return steps