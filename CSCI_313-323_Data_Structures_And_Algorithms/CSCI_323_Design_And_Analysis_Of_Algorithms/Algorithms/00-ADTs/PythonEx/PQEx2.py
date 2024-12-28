# Python already has an implementation of the Priority Queue DS in queue library
# This is a thread-safe implementation and is useful for multi-threaded applications
# For details, look at: https://docs.python.org/3/library/queue.html
from queue import PriorityQueue

pq1 = PriorityQueue()   # This creates a min-heap
pq1.put(4)
pq1.put(2)
pq1.put(5)
pq1.put(1)
pq1.put(3)

while not pq1.empty():
    next_item = pq1.get()
    print(next_item)

print("----------------")

# You can also specify the priority of an item as follows
pq2 = PriorityQueue();  # Create a min-heap
pq2.put((4, 'Read'))
pq2.put((2, 'Play'))
pq2.put((5, 'Write'))
pq2.put((1, 'Code'))
pq2.put((3, 'Study'))

while not pq2.empty():
    next_item = pq2.get()
    print(next_item)