with open('bears.txt', 'r') as bears:
    data = bears.read()



for word in data.splitlines():
    print(word)

'''
Split - turns a string into a list of substrings
split.(sep=''), sep is the separator it determines how to chop

splitlines - splits everything and removes new line characters

read    - turns data into a string completly
readlines - separate each entry with newline at the end  


'''