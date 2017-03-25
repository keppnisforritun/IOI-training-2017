import sys
import re

line = sys.stdin.readline()
assert re.match('^[0-9]+\n$', line)
ts = int(line.strip())
assert 1 <= ts <= 10**5

for t in range(ts):
    line = sys.stdin.readline()
    assert re.match('^[0-9]+\n$', line)
    n = int(line.strip())
    assert 0 <= n <= 10**8

assert sys.stdin.read() == ''
sys.exit(42)

