#  https://www.spoj.com/problems/JULKA/
for i in range(10): 
    total = int(input())
    dif = int(input())
    temp = total - dif
    print(int(temp/2 + dif))
    print(int((temp/2)))

