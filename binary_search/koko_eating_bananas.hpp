#include <iostream>
#include <vector>

using namespace std;

class Solution875 {
public:
    int minEatingSpeed(vector<int> &piles, int H) {
        int l = 1;
        int r = piles[max_element(piles.cbegin(), piles.cend()) - piles.cbegin()];
        while (l < r) {
            int m = (l + r) / 2;
            int h = 0;
            for (const auto &p : piles) {
                h += ((p - 1) / m + 1);
            }
            if (h <= H) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

void test875() {
    vector<int> input({3, 6, 7, 11});
    cout << Solution875().minEatingSpeed(input, 8);
}
