#include <iostream>
#include <vector>

using namespace std;

class Solution1464 {
public:
    int maxProduct(vector<int> &nums) {
        int max_i = 0;
        int max_j = 1;
        int max_val = 0;
        int tmp_val;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                tmp_val = nums[i] * nums[j];
                if (tmp_val > max_val) {
                    max_val = tmp_val;
                    max_i = i;
                    max_j = j;
                }
            }
        }
        return (nums[max_i] - 1) * (nums[max_j] - 1);
    }

    int maxProduct2(vector<int> &nums) {
        int max1 = 0;
        int max2 = 0;
        for (const auto &n : nums) {
            if (n >= max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2) {
                max2 = n;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }

    int maxProduct3(vector<int> &nums) {
        vector<int> counts(1001, 0);
        for (const auto &n : nums) {
            ++counts[n];
        }
        int two_break = 0;
        int res = 0;
        for (int i = 1000; i > 0; --i) {
            if (counts[i] > 0) {
                ++two_break;
                if (two_break == 1) {
                    res = i - 1;
                    if (counts[i] > 1) {
                        return res * res;
                    }
                } else if (two_break == 2) {
                    res *= (i - 1);
                    break;
                }
            }
        }
        return res;
    }
};

void test1464() {
    vector<int> input({3, 4, 5, 2});
    cout << Solution1464().maxProduct3(input);
}
