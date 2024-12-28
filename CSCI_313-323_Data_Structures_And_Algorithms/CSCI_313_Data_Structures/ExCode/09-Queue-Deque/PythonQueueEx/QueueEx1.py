# This is a very bad implementation of Queue using Python Lists
# In this implementation, remove takes O(n)!
class MyQueue:
  def __init__(self):
    self.Q = []         # Queue list

  # Enqueue an object to the end of the Queue 
  def add(self, e): self.Q.append(e)

  # Return the item at the front of the queue without removing it
  def front(self):
    if len(self.Q) == 0: return None
    else:                return self.Q[0]

  # Removes the item at the front of the queue and returns it     
  def remove(self):
    if len(self.Q) == 0: return None
    else:                
       e = self.Q[0]
       self.Q.pop(0)
       return e
    
  # Returns true if the queue is empty, false otherwise
  def isEmpty(self):
    if len(self.Q) == 0: return True
    else               : return False 
    
# Main function    
def main():       
  # Test code for the Queue        
  Q = MyQueue()
  print("Adding 1 to the Q")
  Q.add(1)

  print("Adding 2 to the Q")
  Q.add(2)

  print("Adding John to the Q")
  Q.add("John")

  print("Adding 4.5 to the Q")
  Q.add(4.5)

  print("Item at the front of the Q: {}".format(Q.front()))
  print("Removing the item at the front of the Q: {}".format(Q.remove()))

  print("Adding Alice to the Q")
  Q.add("Alice")

  print("Adding 10 to the Q")
  Q.add(10)

  str = "Removing all Q elements: "
  while Q.isEmpty() == False: str += "{}, ".format(Q.remove())
  print(str)

  if Q.isEmpty(): print("Q is empty")
  else: print("Q is not empty")

# Call the main function
if __name__ == '__main__':
  main()