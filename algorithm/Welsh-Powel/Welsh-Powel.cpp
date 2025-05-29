#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> TimBac(const std::vector<std::vector<int>> &arr, int n)
{
    std::vector<std::pair<int, int>> degreeIndex(n);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
                count++;
        }
        degreeIndex[i] = {count, i};
    }
    std::sort(degreeIndex.begin(), degreeIndex.end(), std::greater<std::pair<int, int>>());
    std::vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = degreeIndex[i].second;
    }
    return result;
}

int main()
{
    std::ifstream f("color2.txt");
    if (!f.is_open())
    {
        std::cerr << "Lỗi khi mở file!" << std::endl;
        return 1;
    }
    int n;
    f >> n;
    std::vector<std::vector<int>> arr(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f >> arr[i][j];
        }
    }
    f.close();

    std::vector<int> arrBac = TimBac(arr, n);
    std::vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (color[arrBac[i]] != 0)
            continue;
        for (int c = 1;; c++)
        {
            bool valid = true;
            for (int j = 0; j < n; j++)
            {
                if (arr[arrBac[i]][j] == 1 && color[j] == c)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                color[arrBac[i]] = c;
                break;
            }
        }
    }

    int maxColor = *std::max_element(color.begin(), color.end());
    std::cout << "So mau da dung: " << maxColor << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Dinh " << i << ": Mau " << color[i] << std::endl;
    }

    return 0;
}