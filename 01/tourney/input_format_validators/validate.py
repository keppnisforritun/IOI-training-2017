import sys
import re

n,m = map(int, sys.stdin.readline().split())
assert 1 <= n <= 20
assert 1 <= m <= 10**6

for i in range(1<<n):
    x = int(sys.stdin.readline())
    assert 1 <= x <= 10**9

for i in range(m):
    ops = sys.stdin.readline().split()
    if ops[0] == 'R':
        assert len(ops) == 3
        a = int(ops[1])
        b = int(ops[2])
        assert 1 <= a <= 2**n
        assert 1 <= b <= 10**9
    elif ops[0] == 'W':
        assert len(ops) == 1
    elif ops[0] == 'S':
        assert len(ops) == 2
        a = int(ops[1])
        assert 1 <= a <= 2**n
    else:
        assert False

assert sys.stdin.read() == ''
sys.exit(42)

