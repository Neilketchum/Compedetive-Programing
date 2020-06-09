#  // given two integers, n and k. You need to find the the maximum value of x, 
# // such that, n! % kx = 0.
# Naive
def fact(n):
    res = 1
    for i in range(1,n+1):
        res = res * i
    return res
def comute(n,k):
    x = 0
    max  = 0
    n = fact(n)
    while(k**x <n):
        if((n % k**x)==0):
            max  = x
        x = x+1
    return max
for i in range(int(input())):
    n,k  = map(int,input().split())
    print(comute(n,k))