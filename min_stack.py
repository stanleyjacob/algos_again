
class MinStack:

    def __init__(self):
        self.min_val = None
        self.my_stack = []
        
    def push(self, x: int) -> None:
        if self.min_val is None:
            self.min_val = x
        elif x < self.min_val:
            self.min_val = x
        self.my_stack.append((x, self.min_val))
        
    def pop(self) -> int:
        if len(self.my_stack) == 0:
            return None
        
        ret_val = self.my_stack.pop()
        if len(self.my_stack) == 0:
            self.min_val = None
        else:
            self.min_val = self.my_stack[-1][1]
            
        return ret_val[0]
        
    def top(self) -> int:
        if len(self.my_stack) == 0:
            return None
        return self.my_stack[-1][0]
        
    def getMin(self) -> int:
        if len(self.my_stack) == 0:
            return None
        return self.min_val
