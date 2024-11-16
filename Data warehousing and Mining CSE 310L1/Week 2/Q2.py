freq = {}
f = open('transactions3.txt', 'r')
for line in f:
    parts = line.strip().split('-')
    objs = parts[1].split()
    for obj in objs:
        if obj in freq:
            freq[obj] += 1
        else:
            freq[obj] = 1
for obj, count in freq.items():
    print(obj + "-" + str(count))
f.close()
