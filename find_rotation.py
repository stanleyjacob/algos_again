
def find_rotation(arr):
	search_range = (0, len(arr) - 1)
	low = search_range[0] 
	high = search_range[1] 
	while (high - low) > 0:
		low = search_range[0]
		high = search_range[1]

		mid = (low + high) // 2
		if arr[mid + 1] < arr[mid]:
			return mid + 1

		if arr[mid] < current_low:
			previous_low = current_low
			current_low = arr[mid]
			curr_index = mid
			search_range = (low + 1, mid)
		elif arr[high] < current_low:
			previous_low = current_low
			current_low = arr[high]
			curr_index = high
			search_range = (mid + 1, high)
		else:
			return curr_index

import random

arr = [4,5,6,7,0,1,2]
print(find_rotation(arr))
