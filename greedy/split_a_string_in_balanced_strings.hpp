#include <iostream>

using namespace std;

class Solution1221 {
public:
    int balancedStringSplit(string s) {
        int count = 0, sum = 0;
        for (char c : s) {
            sum += c == 'R' ? 1 : -1;
            if (sum == 0) ++count;
        }
        return count;
    }
};

void test1221() {
    cout << Solution1221().balancedStringSplit("RLRRLLRLRL") << endl;
    cout << Solution1221().balancedStringSplit("RLLLLRRRLR") << endl;
    cout << Solution1221().balancedStringSplit("LLLLRRRR") << endl;
    cout << Solution1221().balancedStringSplit("RLRRRLLRLL") << endl;
}
