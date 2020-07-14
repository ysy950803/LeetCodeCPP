#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

class Solution1480 {
public:
    static vector<int> runningSum(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            int i_sum = 0;
            for (int j = 0; j < i + 1; ++j) {
                i_sum += nums[j];
            }
            result.push_back(i_sum);
        }
        return result;
    }

    static vector<int> runningSum2(vector<int> &nums) {
        partial_sum(begin(nums), end(nums), begin(nums));
        return nums;
    }

    // BEST
    static vector<int> runningSum3(vector<int> &nums) {
        for (int i = 1; i < nums.size(); ++i) nums[i] += nums[i - 1];
        return nums;
    }
};

void test1480() {
    int a[] = {1, 2, 3, 4, 5};
    vector<int> input(a, a + size(a));
    vector<int> output = Solution1480::runningSum3(input);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
