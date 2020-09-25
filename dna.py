from sys import argv
import sys
import csv
import re

#a program to check for matching dna

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt") 
    exit(1)

else:
    fileDNA = argv[2]
    fDNA = open(fileDNA, "r")
    dna = fDNA.read()
    
    with open(argv[1], "r") as fileData:
        key = csv.DictReader(fileData)
        keyNames = key.fieldnames
        temp = dict()
        
        for name in keyNames :
            temp[name] = temp.get(name,0)
            
        for name in keyNames[1:]:
            seqPattern ="(?:" + name + ")+"
            seqCount = re.findall(seqPattern, dna)
            largest = max(seqCount, key = len, default = '')
            temp[name] = len(largest) // len(name)
            
        for row in key:
            
            for seq in row:
                flag = True
                
                if not row[seq].isalpha():
                    
                    if row[seq] == temp[seq] :
                        continue
                    
                    else:
                        flag = False
                        break
            
            if flag == True:
                print(row['name'])
                exit(0)
                
            else:
                print("No Match")
                        
