import heapq
def UCS(graph,start,end):
    priority_queue=[(0,start)]
    visited={}
    while priority_queue:
        cost,node=heapq.heappop(priority_queue)
        if node==end:
            return cost
        if node in visited and visited[node]<=cost:
            continue
        visited[node]=cost
        for neightbor,weight in graph[node]:
            heapq.heappush(priority_queue,(cost+weight,neightbor))  
    return float("inf")
graph={
    'A':[('C',9),('D',7),('E',13),('F',20)],
    'C':[('H',6)],
    'D':[('H',8),('E',4)],
    'E':[('K',4),('I',3)],
    'F':[('G',4),('I',6)],
    'H':[('K',5)],
    'K':[('B',6)],
    'I':[('K',9),('B',5)]
}
print(UCS(graph,'A','B'))
    