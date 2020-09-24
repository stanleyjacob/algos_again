
def maxRight(arr):
    right_counts = []
    for i in range(len(arr)):
        curr_count = 0
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[i]:
                curr_count += 1
            right_counts.append(curr_count)

    return right_counts
