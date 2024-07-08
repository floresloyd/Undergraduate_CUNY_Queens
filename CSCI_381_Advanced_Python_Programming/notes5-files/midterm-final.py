with open('midterm-final.txt', 'r') as midterm_final:
    data = midterm_final.read()

splitline = data.splitlines()
split_more = [x.split() for x in splitline]


with open('midterm-final-output', 'w') as output:
    output.write("Name  Midterm     Final       Average")
    output.write('\n')

    
    for person in split_more:
        first = person[0]
        last = person[1]
        avg = (int(person[2]) + int(person[3])) / 2
        output.write(f"{first}  {last}  {person[2]}  {person[3]} {avg}")
        output.write('\n')