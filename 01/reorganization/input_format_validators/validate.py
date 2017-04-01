import sys
import re

n = int(sys.stdin.readline())
assert 1 <= n <= 10**5

found = set()
for i in range(n):
    x = int(sys.stdin.readline())
    assert 1 <= x <= 10**7
    if x in found:
        print(x)
    assert x not in found
    found.add(x)

assert sys.stdin.read() == ''
sys.exit(42)

