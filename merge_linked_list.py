
class LinkedList:
    def __init__(self, value):
        self.value = value
        self.next = None

def mergeLinkedLists(headOne, headTwo):
    merged_list = None
	
	if headOne.value < headTwo.value:
		merged_list = headOne
		headOne = headOne.next
	else:
		merged_list = headTwo
		headTwo = headTwo.next
	
	curr_node = merged_list
	while headOne != None and \
		headTwo != None:
		if headOne.value < headTwo.value:
			curr_node.next = headOne
			headOne = headOne.next
		else:
			curr_node.next = headTwo
			headTwo = headTwo.next
		curr_node = curr_node.next
	
	if headOne != None:
		curr_node.next = headOne
		
	if headTwo != None:
		curr_node.next = headTwo
		
	return merged_list
