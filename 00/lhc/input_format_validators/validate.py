import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+\n$', line)
n = int(line.strip())
assert 3 <= n <= 3 * 10**5

parent = [ i for i in range(n) ]

def find(x):
    if parent[x] == x:
        return x
    parent[x] = find(parent[x])
    return parent[x]

for i in range(n-1):
    line = sys.stdin.readline()
    assert re.match('^[0-9]+ [0-9]+\n$', line)
    a,b = map(int,line.strip().split())
    assert 1 <= a <= n
    assert 1 <= b <= n
    assert find(a-1) != find(b-1)
    parent[find(a-1)] = find(b-1)

assert sys.stdin.read() == ''
sys.exit(42)

