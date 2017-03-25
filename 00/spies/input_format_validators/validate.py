import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+ [0-9]+\n$', line)
n,m = map(int,line.strip().split())

assert 1 <= n <= 5000
assert 1 <= m <= 5000

line = sys.stdin.readline()
assert re.match('^[0-9]+\n$', line)
k, = map(int,line.strip().split())

assert 0 <= k <= n*m

seen = set()
for i in range(k):
    line = sys.stdin.readline()
    assert re.match('^[0-9]+ [0-9]+\n$', line)
    a,b = map(int,line.strip().split())
    assert 1 <= a <= n
    assert 1 <= b <= m

    assert (a,b) not in seen
    seen.add((a,b))

assert sys.stdin.read() == ''
sys.exit(42)

