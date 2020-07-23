#include <iostream>
#include <vector>

using namespace std;

class Solution53 {
public:
    // Time Limit Exceeded
    static int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int max = 0;
        for (int len = 1; len <= n; ++len) { // 滑动长度
            for (int j = 0; j < n - len + 1; ++j) {
                int sum = 0;
                for (int k = 0; k < len; ++k) {
                    sum += nums[j + k];
                }
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }

    // O(n)时间复杂度
    static int maxSubArray2(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        int max = nums[0];
        // 在遍历过程中start和end可能是不断移动的，end其实对最终算法没有必要作用
        int start = -1, end = -1;

        for (int i = 0; i < n; ++i) {
            if (start == -1) {
                // 找到第一个不为负的数作为起点
                if (nums[i] >= 0) {
                    start = i;
                    sum = nums[i];

                    // 辅助理解
                    end = i;
                } else {
                    // 如果全都是负数，直接取最大的
                    if (nums[i] > max) {
                        max = nums[i];
                    }
                }
            } else if (start >= 0) {
                // 只要前面的sum小于0，就会导致总和变小，应该丢弃，并刷新起点
                if (sum < 0) {
                    start = i;
                    sum = nums[i];

                    // 辅助理解
                    end = i;
                } else {
                    sum += nums[i];

                    // 辅助理解
                    if (nums[i] >= 0 && sum > max) {
                        end = i;
                    }
                }
            }
            if (start >= 0 && sum > max) {
                max = sum;
            }
        }

        // 辅助理解
        cout << start << " " << end << endl;
        return max;
    }
};

void test53() {
    //             1      4      2  1      4
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int a2[] = {-2, -11, -3, -4, -12, -2, -13, -5, -4};
    vector<int> input(a2, a2 + size(a2));
    cout << Solution53::maxSubArray2(input) << endl;
}
