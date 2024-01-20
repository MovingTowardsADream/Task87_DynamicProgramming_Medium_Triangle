#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<std::vector<int>> tmp = { {triangle[0][0]} };
        for (int i = 1; i < n;i++) {
            tmp.push_back(std::vector<int>(i + 1));
            tmp[i][0] = tmp[i - 1][0] + triangle[i][0];
            tmp[i][i] = tmp[i - 1][i - 1] + triangle[i][i];
        }
        for (int i = 2;i < n;i++) {
            for (int j = 1;j < i;j++) {
                tmp[i][j] = std::min(tmp[i - 1][j - 1], tmp[i - 1][j]) + triangle[i][j];
            }
        }
        return *std::min_element(tmp[n - 1].begin(), tmp[n - 1].end());
    }
};