#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution1403 {
public:
    static vector<int> minSubsequence(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int num : nums) sum += num;
        sum /= 2;

        vector<int> ans;
        int ans_sum = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ans_sum += nums[i];
            ans.push_back(nums[i]);
            if (ans_sum > sum) {
                break;
            }
        }
        return ans;
    }
};

void test1403() {
    int a[] = {4, 3, 10, 9, 8};
    vector<int> input(a, a + size(a));
    vector<int> output = Solution1403::minSubsequence(input);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
