with open('grades.txt', 'r') as grades:
    data = grades.read()




print(f'Raw Data: {data}')
print()

# Split line to separate each person by line
split_by_line = data.splitlines()
print(f"split_by_line: {split_by_line}")
print()

# Further split the array into sub characters
split_even_more = [ x.split() for x in split_by_line if x ]
print(f"split_even_more: {split_even_more}")

def get_average(arr):
    total_grade = sum([int(x) for x in arr])

    length = len(arr)
    return total_grade / length

print()
print('processing ...')
print() 

with open('grades_output.txt.', 'w') as output:
    for person in split_even_more:
        output.write(f"{person[0]}    average =  {"{:.2f}".format(get_average(person[1:]))}")
        output.write('\n')