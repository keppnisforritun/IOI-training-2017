import sys
import random

n = random.randint(3,3 * 10**5)
print(n)

parent = [ i for i in range(n) ]
def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

for i in range(n-1):
    while True:
        a = random.randint(0,n-1)
        b = random.randint(0,n-1)
        if find(a) == find(b):
            continue
        break

    parent[find(a)] = find(b)
    print('%d %d' % (a+1,b+1))

