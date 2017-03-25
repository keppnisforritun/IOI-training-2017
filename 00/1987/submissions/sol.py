from itertools import *
from bisect import *

lst = []
for i in range(1,9):
    for v in permutations("0123456789", i):
        if v[0] != '0':
            lst.append(int(''.join(v)))

lst.sort()

t = int(input())
for i in range(t):
    n = int(input())
    try:
        print(lst[bisect_right(lst,n)])
    except:
        print(102345678)

