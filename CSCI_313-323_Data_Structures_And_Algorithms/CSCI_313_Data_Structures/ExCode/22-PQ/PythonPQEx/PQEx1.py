# An efficient Binary Heap implementation for single-threaded applications
# This example was taken from: https://www.geeksforgeeks.org/heap-queue-or-heapq-in-python/
# importing "heapq" to implement heap queue
import heapq
  
# initializing list
li = [5, 7, 9, 1, 3]
  
# using heapify to convert list into heap (a min-heap)
heapq.heapify(li)
  
# printing created heap
print ("The created heap is: ", end="")
print (li)
  
# using heappush() to push elements into heap
# pushes 4
print("Inserting 4 to the heap...")
heapq.heappush(li, 4)
  
# printing modified heap
print ("The modified heap after push is : ", end="")
print (li)
  
# using heappop() to pop smallest element
print ("The popped and smallest element is : ", end="")
print (heapq.heappop(li))