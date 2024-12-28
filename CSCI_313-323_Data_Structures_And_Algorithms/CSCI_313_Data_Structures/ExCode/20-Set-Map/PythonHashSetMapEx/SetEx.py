# Sets in Python are an unordered set of items with no duplicates
# This corresponds to the HashSet in other Programming Languages
#
# add(item): Adds an item to the set. If the item already exists, it is not added
# remove(item): Removes an item from the set. If the item does not exist, throws an exception
#

S1 = {3, 5, "ali", 4.5, "veli"}
print(S1)
print(len(S1))
for item in S1: print(item)

# add(item): Adds an item to the set. If the item already exists, it is not added
#
S1.add(20)
print(S1)

S1.add('ali')  # No duplicates in a set. So, this does not add 'ali' again.
print(S1)

# remove(item): Removes an item from the set. 
#
S1.remove(4.5)
S1.remove(5)
print(S1)

# find: Does an item exist?
exist = "ali" in S1
print(exist)
if "cemal" not in S1: S1.add("cemal")
print(S1)

if "ali" in S1: S1.remove("ali")
print(S1)

if 30 in S1: S1.remove(30)
print(S1)




