infile=open("C:\\2301358\\pydwws\\input.txt", 'r', encoding="utf-8")


#1번
for i in range(3):
    line=infile.readline()
    print(line.strip())

infile.close()

