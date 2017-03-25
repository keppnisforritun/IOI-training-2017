import sys, random, collections

def distinct(n):
    c = collections.Counter(str(n))
    if any(c[k] > 1 for k in c):
        return False
    return True

def random_distinct(a,b):
    while True:
        v = random.randint(a,b)
        if distinct(v):
            return v

def random_non_distinct(a,b):
    while True:
        v = random.randint(a,b)
        if not distinct(v):
            return v

gentype = sys.argv[1].lower()
n,a,b = map(int, sys.argv[2:5])
func = None
if gentype == "distinct":
    func = random_distinct
elif gentype == "non-distinct":
    func = random_non_distinct
else:
    func = random.randint

print(n)
for i in range(n):
    print(func(a,b))
