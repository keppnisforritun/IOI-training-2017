import sys
import re

n,m,t = map(int,sys.stdin.readline().split())
assert 0 < n <= 10000
assert 0 < m <= 10000
assert 0 < t <= 5000

for i in range(t):
    x,y = map(int, sys.stdin.readline().split())
    assert 0 <= x <= n
    assert 0 <= y <= m

assert sys.stdin.read() == ''
sys.exit(42)


