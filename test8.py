import random

# 읽기
fp = open('file_test_ANSI.txt','r')

lst=[]
lines = fp.readlines()

for line in lines:
    n=float(line.strip())
    lst.append(n)

fp.close()

fp = open('file_test_ANSI.txt','a')
fp.write('\n%s' % str(sum(lst)/len(lst)))
fp.close()  

infile = open("scores.txt", "r") 
outfile = open("scores1.txt", "w") 
count = 0
sum = 0

line = infile.readline() 
while line != "" :
    outfile.write(line) 
    s = float(line) 
    sum += s
    count += 1
    line = infile.readline()

outfile.write("\n평균 = %8.2f\n" % (sum/count)) 
infile.close() 
outfile.close()
