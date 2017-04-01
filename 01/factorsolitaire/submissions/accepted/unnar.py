from math import sqrt, floor

n = int(input())
cost = 0
while n > 1:
    for i in range(2,int(sqrt(n))+1):
        if n%i == 0:
            x = n//i
            n -= x
            cost += i-1
            break
    else:
        n -= 1
        cost += n
print(cost)
