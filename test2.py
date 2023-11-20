infile=open("C:\\2301358\\pydwws\\input.txt", 'r', encoding="utf-8")

#2번
line=infile.read()
lst1=line.split()
max=0
temp=lst1[0]
for i in lst1:
    if(max<len(i)):
        max=len(i)
        temp=i

print("yes" if "well" in lst1 else "no")

print(f"가장 긴 단어는 {i}입니다")

infile.close()