#include <iostream>
#include <vector>

using namespace std;

class Solution1046 {
public:
    static int lastStoneWeight(vector<int> &stones) {
        return 0;
    }
};

void test1046() {
    int a[] = {2, 7, 4, 1, 8, 1};
    vector<int> input(a, a + size(a));
    cout << Solution1046::lastStoneWeight(input) << endl;
}
