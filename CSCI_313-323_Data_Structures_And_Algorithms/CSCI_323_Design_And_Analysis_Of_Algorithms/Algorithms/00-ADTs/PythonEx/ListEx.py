# Lists in Python correspond to ArrayList/LinkedList in other programming languages
# They keep an ordered list of "non-uniform" items. That is, list elements 
# can have different data types such as number, string, even lists!
#
# Here are some of the important list methods
# len(L): Returns the number of elements in the list
#
# append(obj): Append the specified obj to the end of the list
# insert(index, obj): Insert an object at a specified index
#
# pop(): Removes and returns the last item in the list
# pop(index): Removes and returns an item at a specific index
#
# remove(obj): Finds and removes an existing object
#
# index(obj): Returns the index of the first object that equals obj
#             If the obj is NOT in the list, throws a ValueError exception
#
#
A = [5, 4, 9, 1, 3]
print(A)
print("Length of the list is: ", len(A))

print("List elements are the following: [", end="")
for item in A:
   print(item, end=", ")
print("\b\b]")

# append(obj): Append the specified obj to the end of the list
# insert(index, obj): Insert an object at a specified index
#
A.append(20)
A.append(15)
A.insert(2, 12)
print(A)

# pop(): Removes and returns the last item in the list
# pop(index): Removes and returns an item at a specific index
#
A.pop()
A.pop(2)
print(A)

# remove(obj): Finds and removes an existing object
#
A.remove(9)
A.remove(3)
print(A)

# Add lists together
B = [50, 51, 60, 55]
C = A + B   # Add lists A and B, and create a new list
print(C)

# WARNING: This does not make a copy of the list. This is just a pointer assignment
D = A;  # Just points D to the same list
A[0] = 33
D[0] = 44
print(A)
print(D)

# make a copy of the list
D = A.copy()
A[0] = 40
D[0] = 100
print(A)
print(D)

print(A.index(1))

# clear: deletes all elements of the list, and makes an empty list
A.clear()
print(A)

# sort: Sorts the list in ascending order
D.sort()
print(D)


