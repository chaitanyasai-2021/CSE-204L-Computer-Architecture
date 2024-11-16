file=open('transactions2.txt','w')
for i in range(5):
    id=input("Enter transaction id ")
    file.write(id+"- ")
    num=int(input("Enter number of items purchased in transaction "))
    for j in range(num):
        item=input("Enter the item:")
        file.write(item+" ")
    file.write("\n")
file.close()

f=open('transactions2.txt','r')
for each in f:
    print(each)