import random

n = random.randint(1,5000)
m = random.randint(1,5000)
p = random.random() / random.randint(1,n)

arr = []
for i in range(n):
    for j in range(m):
        if random.random() < p:
            arr.append((i,j))
print '%d %d' % (n,m)
print '%d' % len(arr)
random.shuffle(arr)
for (x,y) in arr:
    print '%d %d' % (x+1,y+1)

