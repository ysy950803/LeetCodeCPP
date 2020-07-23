#include <iostream>
#include <vector>

using namespace std;

class Solution1217 {
public:
    static int minCostToMoveChips(vector<int> &chips) {
        int n = chips.size();
        int even_count = 0;
        for (int i = 0; i < n; ++i) {
            if (chips[i] & 1) {
                ++even_count;
            }
        }
        int odd_count = n - even_count;
        return even_count > odd_count ? odd_count : even_count;
    }
};

void test1217() {
    int a[] = {2, 2, 2, 3, 3};
    vector<int> input(a, a + size(a));
    cout << Solution1217::minCostToMoveChips(input) << endl;
}
