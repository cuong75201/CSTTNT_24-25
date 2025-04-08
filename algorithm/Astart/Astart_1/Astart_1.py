
g={}
n=int(input("Nhap vao x(graphx.txt, x:1->5) muon kiem tra: "))
with open(f'graph{n}.txt','r') as file:
    dinh,canh=list(map(int,file.readline().split()))
    start,end=list(map(int,file.readline().split()))
    for _ in range(canh):
        line = file.readline().split()
        if len(line) == 3: 
            a, b, c = map(int, line)
            g[(a, b)] = c
        else:
            print(f"Lỗi dòng: {line}") 

    h=list(map(int,file.readline().split()))
pos=start
open=[start]
close=[]
f={start:h[start]}
while(pos!=end):
    lst=[]
    for key,value in g.items():
        if (pos in key) and (key[0] not in close) and (key[1] not in close):
            f[key[(key.index(pos)+1)%2]]=value+h[key[(key.index(pos)+1)%2]-1]
            open.append((key[(key.index(pos)+1)%2]))
            lst.append((key[(key.index(pos)+1)%2]))
    open.remove(pos)
    close.append(pos)
    pos=min(lst,key =lambda node:f[node])
close.append(end)
print(close)
cost=0
for i in range(len(close)-1):
    if (close[i],close[i+1]) in g: 
        cost+=g[(close[i],close[i+1])]
    else:
        cost +=g[(close[i+1],close[i])]
print(cost)
