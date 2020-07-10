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

    static int maxSubArray2(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        int max = nums[0];
        int start = -1, end = -1;

        for (int i = 0; i < n; ++i) {
            if (start == -1) {
                if (nums[i] >= 0) {
                    start = i;
//                    end = i;
                    sum = nums[i];
                } else {
                    if (nums[i] > max) {
                        max = nums[i];
                    }
                }
            } else if (start >= 0) {
                if (sum < 0) {
                    start = i;
//                    end = i;
                    sum = nums[i];
                } else {
                    sum += nums[i];
//                    if (nums[i] >= 0 && sum > max) {
//                        end = i;
//                    }
                }
            }
            if (start >= 0 && sum > max) {
                max = sum;
            }
        }
//        cout << start << " " << end << endl;
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
