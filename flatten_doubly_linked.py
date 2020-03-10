class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        
        if head is None:
            return
        
        temp = Node(0, None, head, None)
            
        my_stack = [head]
        prev_node = temp
        while len(my_stack) != 0:
            
            curr_node = my_stack.pop()
            
            prev_node.next = curr_node
            curr_node.prev = prev_node
            
            if curr_node.next is not None:
                my_stack.append(curr_node.next)
                
            if curr_node.child is not None:
                my_stack.append(curr_node.child)
                curr_node.child = None
                
            prev_node = curr_node
        
        temp.next.prev = None
        return temp.next 
