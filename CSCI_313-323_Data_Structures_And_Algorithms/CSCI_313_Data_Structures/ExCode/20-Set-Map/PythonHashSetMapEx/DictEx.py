# Dictionaries in Python are unique "key/value" pairs, and 
# correspond to HashMap in other Programming Languages
#
# 
#
#
D = {3: "Ali", 5: "Veli", "Tree": "OK", 4.5: 88}
print(D)
print(len(D))
for key in D: print("(" + str(key) + ", " + str(D[key]) + ")")

print(D.keys());         # Get a list of keys
print(D.values());       # Get a list of values
print(D.items());        # Get a list of (key, value) tuples

# Add a new (key/value) pair
#
D["Cem"] = "Smart"
print(D)

# Remove an existing item. If the item does not exist, then throws an exception
if "Tree" in D: D.pop("Tree")
if 99 in D: D.pop(99)
print(D)

# Get the value of a key
if 4.5 in D: print(D[4.5])
if 4.5 in D: print(D.get(4.5))

# clear(): Deletes all (key/value) pairs in the dictionary
D.clear()
print(D)