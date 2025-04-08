
matrix=[]
with open('color2b.txt','r') as file:
    n=file.readline().strip()
    for line in file:
        row=list(map(int,line.strip().split()))
        matrix.append(row)
Bac=[row.count(1) for row in matrix]
color={}
ban={}
for i in range(int(n)):
    ban[i]=[]
while(any(x>0 for x in Bac)):
    for i in range(len(Bac)):   
        if(Bac[i] == max(Bac)):
            a=0
            Bac[i]=0
            while(a in ban[i]):
                a+=1
            color[i]=a
            for j in range(len(Bac)):
                if matrix[i][j]==1:
                    Bac[j]=Bac[j]-1
                    ban[j].append(color[i])
for i in range(len(Bac)):
    if(i not in color):
        a=0
        while(a in ban[i]):
            a+=1
        color[i]=a
color_set=set()
for key,value in color.items():
    color_set.add(value)
print(len(color_set))