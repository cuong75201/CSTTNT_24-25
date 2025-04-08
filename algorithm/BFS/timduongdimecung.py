from collections import deque
def bfs(maze,start,goal):
    direction=[(-1,0),(1,0),(0,1),(0,-1)]
    rows=len(maze)
    cols=len(maze[0])
    q=deque([(start, [start])])
    visited=set()
    visited.add(start)
    while(q):
        (x,y),path=q.popleft()
        if(x,y)==goal: return path
        for dx,dy in direction:
            nx,ny=x+dx,y+dy
            if 0<=nx<rows and 0<=ny<cols and maze[nx][ny]==0:
                if(nx,ny) not in visited:
                    visited.add((nx,ny))
                    q.append((nx,ny),path+[(nx,ny)])
    return None
start=(0,0)
q=deque([(start, [start])])
print(q.popleft())