transac = []

with open('transactions3.txt', 'r') as f:
    for row in f:
        objs = row.strip().split('-')[1].split()
        transac.append(objs)

for i, tra in enumerate(transac):
    print(f"After reading T{i+1}")
    for j in range(len(tra)):
        for k in range(j + 1, len(tra)):
            objset = [tra[j], tra[k]]
            print(" ".join(objset))
