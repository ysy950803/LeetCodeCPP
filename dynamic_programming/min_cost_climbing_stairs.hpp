#include <iostream>
#include <vector>

using namespace std;

class Solution746 {
public:
    int findNextMinCost(vector<int> &cost, int cur, vector<int> &cache) {
        if (cur >= cost.size()) {
            return 0;
        }
        if (cache[cur] == -1) {
            int next_1_c = findNextMinCost(cost, cur + 1, cache);
            int next_2_c = findNextMinCost(cost, cur + 2, cache);
            cache[cur] = cost[cur] + min(next_1_c, next_2_c);
        }
        return cache[cur];
    }

    int minCostClimbingStairs(vector<int> &cost) {
        vector<int> cache(cost.size(), -1);
        return min(findNextMinCost(cost, 0, cache), findNextMinCost(cost, 1, cache));
    }

    int minCostClimbingStairs2(vector<int> &cost) {
        int a = cost[0], b = cost[1];
        int t_a;
        for (int i = 2; i < (int) cost.size(); ++i) {
            t_a = a;
            a = b;
            b = min(t_a, b) + cost[i]; // 前置最小值 + 当前值
        }
        return min(a, b);
    }

    // BEST
    int minCostClimbingStairs3(vector<int> &cost) {
        int n = (int) cost.size();
        for (int i = 2; i < n; ++i) {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};

void test746() {
    int a[] = {10, 15, 20};
    int b[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> input(b, b + size(b));
    int output = Solution746().minCostClimbingStairs3(input);
    cout << output << endl;
}
