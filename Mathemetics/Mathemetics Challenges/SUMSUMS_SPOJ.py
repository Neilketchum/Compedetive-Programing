# Naive Solution
n,t = map(int,in put().split())
sum_cow = 0
cows = []
MOD = 987654321
for i in range(n):
    temp = int(input())
    cows.append(temp)
for i in range(t):
    sum_cow = sum(cows)%MOD
    for j in range(n):
        cows[j] = (sum_cow%MOD - cows[j]%MOD)%MOD
for i in range(n):
    print(cows[i])