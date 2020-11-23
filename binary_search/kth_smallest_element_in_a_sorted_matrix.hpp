#include <iostream>
#include <vector>

using namespace std;

class Solution378 {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1];
        while (l < r) {
            int m = (l + r) / 2;
            int total = 0; // 根据upper_bound特性，total就是不超过m的实际个数
            for (const auto &row : matrix) {
                total += (upper_bound(row.cbegin(), row.cend(), m) - row.cbegin());
            }
            if (total >= k) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

void test378() {
    vector<vector<int>> input({{1,  5,  9},
                               {10, 11, 13},
                               {12, 14, 15}});
    cout << Solution378().kthSmallest(input, 8);
}
