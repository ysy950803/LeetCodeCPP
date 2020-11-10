#include <iostream>
#include <vector>

using namespace std;

class Solution198 {
public:
     int rob(vector<int> &nums) {
        int n = nums.size();
        int dp[n + 2];
        dp[n] = 0;
        dp[n + 1] = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
};

void test198() {
    int a[] = {2, 7, 9, 3, 1};
    vector<int> input(a, a + size(a));
    cout << Solution198().rob(input) << endl;
}
