#include <iostream>
#include <vector>

using namespace std;

class Solution213 {
public:
    int rob_base(vector<int> &nums) {
        int n = nums.size();
        int dp[n + 2];
        dp[n] = 0;
        dp[n + 1] = 0;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }

    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> a(nums.begin(), nums.end() - 1);
        vector<int> b(nums.begin() + 1, nums.end());
        return max(rob_base(a), rob_base(b));
    }

    int rob2(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);

        auto rob_base2 = [&nums](int start, int end) {
            int first = nums[start];
            int second = max(nums[start], nums[start + 1]);
            for (int i = start + 2; i <= end; ++i) {
                int curr = max(second, first + nums[i]);
                first = second;
                second = curr;
            }
            return second;
        };
        return max(rob_base2(0, nums.size() - 2),
                   rob_base2(1, nums.size() - 1));
    }
};

void test213() {
    int a[] = {1, 2, 3, 1};
    vector<int> input(a, a + size(a));
    cout << Solution213().rob2(input) << endl;
}
