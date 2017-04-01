import random

n = 10000
m = 10000
t = 5000

print('%d %d %d' % (n,m,t))

used = set()
for i in range(t):
    while True:
        x = random.randint(0,n)
        y = random.randint(0,m)
        if (x,y) in used:
            continue
        used.add((x,y))
        break
    print('%d %d' % (x,y))

