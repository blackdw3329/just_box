infile=open("C:\\2301358\\pydwws\\input.txt", 'r', encoding="utf-8")

#3번
N=int(input("행 번호를 입력하시오: "))

for i in range(N):
    line=infile.readline().strip()

print(f"3번 행은 {line}입니다")

infile.close()