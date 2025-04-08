#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

bool TestArr(const std::vector<int> &a, int b)
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
    FILE *f = fopen("tsp3b.txt", "rt");
    if (f == nullptr)
    {
        std::cerr << "Không thể mở file GTS2a.txt!\n";
        return 1;
    }

    int n, m;
    if (fscanf(f, "%d %d", &n, &m) != 2)
    {
        std::cerr << "Lỗi đọc số n, m!\n";
        fclose(f);
        return 1;
    }

    std::vector<int> p(m);
    for (int i = 0; i < m; i++)
    {
        if (fscanf(f, "%d", &p[i]) != 1)
        {
            std::cerr << "Lỗi đọc danh sách điểm xuất phát!\n";
            fclose(f);
            return 1;
        }
    }

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

    int bestcost = INT_MAX;
    std::vector<int> besttour;

    for (int c = 0; c < m; c++)
    {
        int u = p[c] - 1;
        std::vector<int> tour = {u};
        int v = u, cost = 0;

        while (tour.size() < n)
        {
            int minCost = INT_MAX, w = -1;
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

        if (bestcost > cost)
        {
            bestcost = cost;
            besttour = tour;
        }
    }

    std::cout << "Chi phí tốt nhất: " << bestcost << "\n";
    std::cout << "Lộ trình tốt nhất: ";
    for (int city : besttour)
    {
        std::cout << city + 1 << " ";
    }
    std::cout << "\n";

    return 0;
}
