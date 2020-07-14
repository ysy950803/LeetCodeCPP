#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution1365 {
public:
    static vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        int count;
        for (int i = 0; i < n; ++i) {
            count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && nums[j] < nums[i]) {
                    ++count;
                }
            }
            ans[i] = count;
        }
        return ans;
    }

    // BEST
    static vector<int> smallerNumbersThanCurrent2(vector<int> &nums) {
        int n = nums.size();
        vector<int> trans(102, 0);
        vector<int> ans(n);

        for (int i = 0; i < n; ++i) ++trans[nums[i] + 1];
        for (int j = 2; j < 102; ++j) trans[j] += trans[j - 1];
        for (int k = 0; k < n; ++k) ans[k] = trans[nums[k]];
        return ans;
    }
};

void test1365() {
    int a[] = {5, 0, 10, 0, 10, 6};
    vector<int> input(a, a + size(a));
    vector<int> output = Solution1365::smallerNumbersThanCurrent2(input);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
