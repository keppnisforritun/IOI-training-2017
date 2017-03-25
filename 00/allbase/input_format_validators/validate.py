import sys
import re
line = sys.stdin.readline()
assert re.match('^[1-9][0-9]*\n$', line)
assert 2 <= int(line) <= 10**12

assert sys.stdin.read() == ''
sys.exit(42)

