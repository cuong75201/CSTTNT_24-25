import heapq

matrix = []
g = {}

# Đọc dữ liệu từ file
with open('graph2.txt', 'r') as file:
    lenmatrix, start, end = map(int, file.readline().split())
    start -= 1
    end -= 1
    for i in range(lenmatrix):
        matrix.append(list(map(int, file.readline().split())))
    h = list(map(int, file.readline().split()))

# Xây dựng đồ thị dưới dạng dictionary
for row in range(lenmatrix):
    g[row] = []
    for col in range(lenmatrix):
        if matrix[row][col] != 0:
            g[row].append((col, matrix[row][col]))

print("Đồ thị:", g)

# A* Search
open_set = [(h[start], start)]  # (f-score, node)
heapq.heapify(open_set)
came_from = {}
g_score = {node: float('inf') for node in range(lenmatrix)}
g_score[start] = 0
f_score = {node: float('inf') for node in range(lenmatrix)}
f_score[start] = h[start]

while open_set:
    _, pos = heapq.heappop(open_set)

    if pos == end:
        break  # Tìm thấy đường đi

    if pos not in g:
        print(f"Node {pos} không có hàng xóm, dừng thuật toán!")
        break

    for neighbor, weight in g[pos]:
        tentative_g_score = g_score[pos] + weight
        if tentative_g_score < g_score[neighbor]:  
            came_from[neighbor] = pos
            g_score[neighbor] = tentative_g_score
            f_score[neighbor] = g_score[neighbor] + h[neighbor]
            heapq.heappush(open_set, (f_score[neighbor], neighbor))

# Truy vết đường đi
path = []
node = end
while node in came_from:
    path.append(node)
    node = came_from[node]
path.append(start)
path.reverse()

# Kiểm tra nếu không có đường đi
if end not in came_from:
    print("Không có đường đi từ", start + 1, "đến", end + 1)
else:
    # Tính tổng chi phí
    total_cost = sum(matrix[path[i]][path[i + 1]] for i in range(len(path) - 1))

    print("Đường đi:", [x + 1 for x in path])  # In node theo chỉ số 1-based
    print("Chi phí:", total_cost)