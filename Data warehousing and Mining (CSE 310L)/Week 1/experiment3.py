import random
file=open('transactions3.txt','w')
for i in range(1,10001):
    file.write("T"+str(i)+"- ")
    for j in range(random.randint(3,10)):
        file.write(str(random.randint(1,50))+" ")
    file.write("\n")
file.close()


file=open('transactions3.txt','r')
print(file.read())
file.close()