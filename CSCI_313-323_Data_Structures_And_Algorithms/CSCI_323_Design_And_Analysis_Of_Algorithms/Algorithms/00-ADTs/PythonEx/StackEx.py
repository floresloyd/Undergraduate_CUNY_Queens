# There is no Stack DS in Python, but we can easily implement one using a list
# Recall that the lists have append and pop operations already. 
# We can simply use them to implement a Stack
class Stack:
  def __init__(self):
    self.S = []         # Stack list

  # Push an object to the stack 
  def push(self, item): self.S.append(item)

  # Return the item at the top of the stack without removing it
  def top(self):
    if len(self.S) == 0: return None
    else:                return self.S[len(self.S)-1]

  # Removes the item at the top of the stack and returns it     
  def pop(self):
    if len(self.S) == 0: return None
    else:                return self.S.pop()
    
  # Returns true if the stack is empty, false otherwise
  def isEmpty(self):
    if len(self.S) == 0: return True
    else               : return False  
    
       
# Test code for the stack        
S = Stack()
print("Adding 1 to the Stack")
S.push(1)

print("Adding 2 to the Stack")
S.push(2)

print("Adding John to the Stack")
S.push("John")

print("Adding 4.5 to the Stack")
S.push(4.5)

print("Item at the top of the stack: {}".format(S.top()))
print("Removing the item at the top of the stack: {}".format(S.pop()))

print("Adding Alice to the Stack")
S.push("Alice")

print("Adding 10 to the Stack")
S.push(10)

str = "Popping off all stack elements: "
while S.isEmpty() == False: str += f"{S.pop()}, "
print(str)
