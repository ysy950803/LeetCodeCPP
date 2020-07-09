#include <iostream>

using namespace std;

class Solution70 {
public:
    // 1: 1
    // 2: 2
    // 3: 3
    // 4: 5
    // 5: 8
    // 6: 13
    // Why Fibonacci? Try to think it:
    // stair[n - 2] with 2 steps to stair[n], so we have f(n - 2) ways.
    // stair[n - 1] with 1 step to stair[n], so we have f(n - 1) ways.
    // Finally Get: f(n) = f(n - 1) + f(n - 2)
    static int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int f1 = 1, f2 = 2;
        int tmp;
        for (int i = 3; i <= n; ++i) {
            tmp = f1;
            f1 = f2;
            f2 += tmp;
        }
        return f2;
    }
};

void test70() {
    cout << Solution70::climbStairs(6) << endl;
}
