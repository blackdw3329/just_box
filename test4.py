start=ord('A')
end=ord('Z')
for i in range(start,end+1):
    ch=chr(i)
    filename='d://temp//'+ch+'.txt'
    infile=open(filename,'w',encoding='utf-8')
    infile.write(ch)
    infile.close()
