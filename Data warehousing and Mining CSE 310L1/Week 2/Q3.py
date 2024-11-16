from collections import defaultdict

obj_tr = defaultdict(list)

with open('transactions3.txt', 'r') as f:
    for row in f:
        ele = row.strip().split('-')
        t_id = ele[0]
        objs = ele[1].split()
        for item in objs:
            obj_tr[item].append(t_id)

with open('transactions4.txt', 'w') as f:
    for item, transac in obj_tr.items():
        f.write(item + "-" + " ".join(transac) + "\n")
