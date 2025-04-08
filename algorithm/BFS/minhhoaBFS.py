from collections import deque
def inp():
    adj={}
    visited={}
    n=int(input("Nhap so dinh: "))
    m=int(input("Nhap so canh: "))
    for i in range(m):
        x,y=(map(str,input("Nhap 2 dinh cua canh ").split()))
        if x not in adj:
            adj[x] = []
            visited[x]=False

        if y not in adj:
            adj[y] = []
            visited[y]=False
        adj[x].append(y)
        adj[y].append(x)
        
    return adj,visited   
def bfs(u):
    # Khoi tao 
    adj,visited=inp()
    queue=deque()
    queue.append(u)
    visited[u]=True
    # Lap 
    while(queue):
        v=queue.popleft()
        print(f' {v} ',end=" ")
        for value in adj[v]:
            if(visited[value]==False):
                queue.append(value)
                visited[value]=True
bfs("1")


