import os
f=open("C:\\2301358\\pydwws\\input.txt", 'r', encoding="utf-8")

line=f.read()
lst1=line.split()

count=0
for l in lst1:
    if l=="is":
        count+=1

print(lst1.count('is'))

print(f"is의 개수: {count}")