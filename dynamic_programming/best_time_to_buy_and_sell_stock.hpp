#include <iostream>
#include <vector>

using namespace std;

class Solution121 {
public:
    // Time Limit Exceeded
    int maxProfit(vector<int> &prices) {
        int n = (int) prices.size() - 1;
        vector<vector<int>> diff_map(n);
        for (int i = 0; i < n; ++i) {
            diff_map[i].resize(n - i);
            for (int j = 0; j < n - i; ++j) {
                diff_map[i][j] = prices[j + i + 1] - prices[i];
            }
        }

        int max = 0;
        for (int i = 0; i < n; ++i) {
            for (int j_v : diff_map[i]) {
                if (j_v > max) {
                    max = j_v;
                }
            }
        }
        return max;
    }

    // Time Limit Exceeded
    int maxProfit2(vector<int> &prices) {
        int max = 0;
        int n = (int) prices.size() - 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                int tmp = prices[j + i + 1] - prices[i];
                if (tmp > max) {
                    max = tmp;
                }
            }
        }
        return max;
    }

    // BEST
    int maxProfit3(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }

        int buy = prices[0];
        int sell = 0;
        for (int i = 1; i < (int) prices.size(); ++i) {
            int diff = prices[i] - buy;
            if (diff == 0) continue;
            if (diff > 0) {
                if (diff > sell) {
                    sell = diff;
                }
            } else {
                buy = prices[i];
            }
        }
        return sell;
    }
};

void test121() {
    int a[] = {7, 1, 5, 3, 6, 4};
    int b[] = {7, 6, 4, 3, 1};
    int e[] = {};
    vector<int> input(e, e + 0);
    int output = Solution121().maxProfit3(input);
    cout << output << endl;
}
