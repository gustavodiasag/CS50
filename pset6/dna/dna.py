from sys import argv
import csv

def main():
    if len(argv) != 3:
        print("Usage: python dna.py file.csv file.txt")

    with open(argv[2]) as txt_file:
        dna = txt_file.read()

    keys = []
    values = {}
    with open(argv[1]) as csv_file:
        reader = csv.reader(csv_file)
        keys = next(reader)[1:] # Returns me the header of the csv file without "names", so my list will only store the name of keys
        for row in reader:
            values[row[0]] = [int(value) for value in row[1:]] # Iterates through my reader rows and assigns my dicionary's keys to the names in the file, and it's values to lists of integers

    matches = []
    for key in keys:
        # Here I'm passing my function the value of each key to generate the matches with the dna len(keys) times
        calculateStr(key, dna, matches)

    # Checking inside the items of my values dictionaty for the list of matches I got from calculateStr
    for key, value in values.items():
        if value == matches:
            print(key)
            exit(0) # This early exit gives me the power to stop running my program when my condition is satisfied, therefore it won't print "No match"
    print("No match")

def calculateStr(key, dna, matches): # Let's say the current key is TCTAG
    match = 0
    max_match = 0
    i = 0
    while i < len(dna):
        interval = dna[i:i+len(key)] # Current interval is dna[0:0+5] so i'm looking to the characters 0,1,2,3,4
        if interval == key: # If the characters I just got are, in this sequence, T,C,T,A,G, that means i got one match
            match += 1
            max_match = max(match, max_match) # Since this is my first match, i'll consider it to be my maximum one
            i += len(key) # Also, once I got a match, I want to check if there is just one or if there are more, so now i'll look to 5,6,7,8,9
        else:
            match = 0 # If there are more matches, the loop won't reach this else yet, but when it does, i want to "restart" my match variable since it's value is already stored in max_match
            i += 1 # And now, if those 5,6,7,8,9 also matched my key and the next interval didn't, I'll now check the interval starting from 10th posiiton
    matches.append(max_match) # If i got 2 as a maximum match for this key, that's the value I'm going to append to my matches list

main()
