
import random

class RandomizedSet:

    def __init__(self):
        self.my_set = {}
        self.my_arr = []
        self.max_ind = 0
        
        
    def insert(self, val: int) -> bool:
        if val in self.my_set:
            return False
        self.my_set[val] = self.max_ind
        self.max_ind += 1
        self.my_arr.append(val)
        return True

    
    def remove(self, val: int) -> bool:
        if val in self.my_set:
            target_ind = self.my_set[val]
            self.my_arr[target_ind] = self.my_arr[-1]
            self.my_set[self.my_arr[-1]] = target_ind
            del self.my_arr[-1]
            del self.my_set[val]
            self.max_ind -= 1
            return True
        return False
        

    def getRandom(self) -> int:
        my_ind = random.randint(0, len(self.my_arr) - 1)
        return self.my_arr[my_ind]
