#include <iostream>
#include <vector>

using namespace std;

class Solution1470 {
public:
    // BEST
    static vector<int> shuffle(vector<int> &nums, int n) {
        int len = n * 2;
        int a[len];
        for (int i = 0, j = 0; i < len; i += 2, ++j) {
            a[i] = nums[j];
            a[i + 1] = nums[j + n];
        }
        return vector<int>(a, a + len);
    }

    static vector<int> shuffle2(vector<int> &nums, int n) {
        int len = n * 2;
        int a[len];
        for (unsigned int i = 0; i < len; ++i) {
            a[i] = nums[i / 2 + (i & 1u) * n];
        }
        return vector<int>(a, a + len);
    }

    static vector<int> shuffle3(vector<int> &nums, int n) {
        // 0 1 2 3 a b c d  // 0 a 1 b 2 c 3 d

        // 0 2 1   a
        // 0 a 1   2

        static const auto &dest = [](int i, int n) {
            return (i < n) ? 2 * i : 2 * (i - n) + 1;
        };
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                continue;
            }
            int j = i;
            do {
                j = dest(j, n);
                swap(nums[i], nums[j]);
                nums[j] = -nums[j];
            } while (j != i);
        }
        for (auto &num : nums) {
            num = -num;
        }
        return nums;
    }
};

void test1470() {
    int a[] = {0, 1, 2, 3, 0, 1, 2, 3};
    vector<int> input(a, a + size(a));
    vector<int> output = Solution1470::shuffle(input, size(a) / 2);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
