
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

    
class MinStackImproved:

    def __init__(self):
        self.min_val = None
        self.my_stack = []
        self.min_stack = []

        
    def push(self, x: int) -> None:
        
        if self.min_val is None:
            self.min_stack.append([x, 1])
            self.min_val = x
        elif x < self.min_val:
            self.min_stack.append([x, 1])
            self.min_val = x
        elif x == self.min_val:
            self.min_stack[-1][1] += 1
        self.my_stack.append(x)

        
    def pop(self) -> None:
        
        if self.min_stack[-1][0] == self.my_stack[-1]:
            self.min_stack[-1][1] -= 1
        if self.min_stack[-1][1] == 0:
            self.min_stack.pop()
            if len(self.min_stack) == 0:
                self.min_val = None
            else:
                self.min_val = self.min_stack[-1][0]

        self.my_stack.pop()
        
    def top(self) -> int:
        if len(self.my_stack) == 0:
            return None
        return self.my_stack[-1]

    
    def getMin(self) -> int:
        if len(self.min_stack) == 0:
            return None
        return self.min_stack[-1][0]
