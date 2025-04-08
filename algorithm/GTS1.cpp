#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

bool TestArr(std::vector<int> &a, int b)
{
    for (int x : a)
    {
        if (x == b)
            return false;
    }
    return true;
}

int main()
{
    FILE *f = fopen("tsp1b.txt", "rt");
    if (f == nullptr)
    {
        std::cerr << "Không thể mở tệp!\n";
        return 1;
    }

    int n, u;
    if (fscanf(f, "%d %d", &n, &u) != 2)
    {
        std::cerr << "Lỗi đọc dữ liệu!\n";
        fclose(f);
        return 1;
    }
    u--;

    std::vector<std::vector<int>> arr(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fscanf(f, "%d", &arr[i][j]) != 1)
            {
                std::cerr << "Lỗi đọc dữ liệu ma trận!\n";
                fclose(f);
                return 1;
            }
        }
    }
    fclose(f); // Đóng file ngay sau khi đọc xong

    std::vector<int> tour = {u};
    int v = u, cost = 0;

    while (tour.size() < n)
    {
        int minCost = INT_MAX;
        int w = -1;

        for (int i = 0; i < n; i++)
        {
            if (v != i && TestArr(tour, i) && arr[v][i] < minCost)
            {
                minCost = arr[v][i];
                w = i;
            }
        }

        if (w == -1)
        {
            std::cerr << "Lỗi: Không tìm thấy đường đi hợp lệ!\n";
            return 1;
        }

        cost += minCost;
        tour.push_back(w);
        v = w;
    }

    cost += arr[v][u];
    tour.push_back(u);

    std::cout << "Tổng chi phí: " << cost << "\n";
    std::cout << "Lộ trình: ";
    for (int city : tour)
    {
        std::cout << city + 1 << " ";
    }
    std::cout << "\n";

    return 0;
}
