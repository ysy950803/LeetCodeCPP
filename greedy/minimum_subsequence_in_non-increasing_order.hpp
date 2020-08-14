#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution1403 {
public:
    vector<int> minSubsequence(vector<int> &nums) {
        int sum = 0, ans_sum = 0;
        auto begin = nums.begin();
        sort(begin, nums.end(), greater<>()); // dec

        for (int num : nums) sum += num;
        sum /= 2;

        for (int i = 0; i < nums.size(); ++i) {
            ans_sum += nums[i];
            if (ans_sum > sum) {
                nums = vector<int>(begin, begin + i + 1);
                break;
            }
        }
        return nums;
    }
};

void test1403() {
    int a[] = {4, 3, 10, 9, 8};
    vector<int> input(a, a + size(a));
    vector<int> output = Solution1403().minSubsequence(input);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
