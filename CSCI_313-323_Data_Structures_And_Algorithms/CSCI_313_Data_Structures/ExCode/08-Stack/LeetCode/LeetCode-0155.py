class MinStack:
    
    def __init__(self):
        self.S1 = []
        self.S2 = []  # Monotonic stack    

    def push(self, val: int) -> None:
        self.S1.append(val)
        if len(self.S2) == 0 or val <= self.S2[-1]:
            self.S2.append(val)        

    def pop(self) -> None:
        x = self.S1.pop()
        if x == self.S2[-1]:
            self.S2.pop()        

    def top(self) -> int:
        return self.S1[-1]        

    def getMin(self) -> int:
        return self.S2[-1]                


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
