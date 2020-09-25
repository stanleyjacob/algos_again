
def findMinHeight(arr):
    pass


class BST:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, curr_value):
        if curr_value < self.curr_value:
            if self.left is None:
                self.left = BST(curr_value)
            else:
                self.left.insert(curr_value)
        else:
            if self.right is None:
                self.right = BST(curr_value)
            else:
                self.right.insert(curr_value)
