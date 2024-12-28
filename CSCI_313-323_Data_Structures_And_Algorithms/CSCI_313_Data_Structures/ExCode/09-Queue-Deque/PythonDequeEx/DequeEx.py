# We can simply make use of the deque class from collections,
# which has the following major methods
#
# append(x): Adds element x to the right end of the deque.
# appendleft(x): Adds element x to the left end of the deque.
# pop(): Removes and returns the rightmost element from the deque.
# popleft(): Removes and returns the leftmost element from the deque.

from collections import deque

class MyDeque:
  def __init__(self):
    self.Q = deque()

  # Add to the beginning
  def addFirst(self, e): self.Q.appendleft(e)

  # Add to the end
  def addLast(self, e): self.Q.append(e)

  # First element on the left
  def first(self):
    if len(self.Q) == 0: return None
    else:                return self.Q[0]

  # Last element (back)
  def last(self):
    if len(self.Q) == 0: return None
    else:                return self.Q[-1]

  # Removes the element at the front of the deque and returns it     
  def removeFirst(self):
    if len(self.Q) == 0: return None
    else:                
       e = self.Q[0]
       self.Q.popleft()
       return e
    
  # Removes the element at the back of the deque and returns it     
  def removeLast(self):
    if len(self.Q) == 0: return None
    else:                
       e = self.Q[-1]
       self.Q.pop()
       return e
        
  # Returns true if the queue is empty, false otherwise
  def isEmpty(self):
    if len(self.Q) == 0: return True
    else               : return False

  # Returns the size of the deque
  def size(self): return len(self.Q)
    
# Main function    
def main():       
    # Test code for the Queue        
    print("Creating a deque...")

    dq = MyDeque()

    print("addLast(4)")
    dq.addLast(4)

    print("addLast(3)")
    dq.addLast(3)

    print("addFirst(7)")
    dq.addFirst(7)

    print("addFirst(1)")
    dq.addFirst(1)

    print("addFirst(9)")
    dq.addFirst(9)

    print("Deque elements should be: <9, 1, 7, 4, 3> ")
    print("Number of elements in the deque: ", dq.size())
    print("Element at the front of the deque: ", dq.first())
    print("Element at the end of the deque: ", dq.last())
    print("Removing the front element of the deque.")
    dq.removeFirst()
    print("Element at the front of the deque now: ", dq.first())
    print("Removing the last element of the deque.")
    dq.removeLast()
    print("Element at the end of the deque now: ", dq.last())
    print("Is the deque empty? " + ("Yes" if dq.isEmpty() else "No"))

    print("Removing the deque elements in order: ", end="")
    while not dq.isEmpty():
      print(dq.removeFirst(), end=", ")
    print()
    print("Is the deque empty? " + ("Yes" if dq.isEmpty() else "No"))

# Call the main function
if __name__ == '__main__':
  main()