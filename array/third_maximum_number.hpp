#include <iostream>
#include <vector>

using namespace std;

class Solution414 {
public:
    int thirdMax(vector<int> &nums) {
        int max1 = nums[0];
        int max2 = -2147483648;
        int max3 = -2147483648;
        int count1 = max1 > -2147483648 ? 1 : 0;
        int count2 = max1 > -2147483648 ? 0 : 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max1) {
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
                ++count1;
            } else if (max1 > nums[i] && nums[i] > max2) {
                max3 = max2;
                max2 = nums[i];
                ++count1;
            } else if (max2 > nums[i] && nums[i] > max3) {
                max3 = nums[i];
                ++count1;
            }
            if (nums[i] == -2147483648) {
                count2 = 1;
            }
        }
        return count1 + count2 < 3 ? max1 : max3;
    }
};

void test414() {
    int a[] = {0, 1, -2147483648};
    vector<int> input(a, a + size(a));
    cout << Solution414().thirdMax(input) << endl;
}
