import csv 

with open('name-age-city.csv') as data:
    # create csv reader
    csv_reader = csv.reader(data)
    
    #skip header
    next(csv_reader)

    for row in csv_reader:
        print(row)