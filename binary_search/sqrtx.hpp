#include <iostream>
#include <vector>

using namespace std;

class Solution69 {
public:
    // 这种写法Python可以过，但是C++会overflow在l + r和m * m上
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 2;
        int r = x;
        while (l < r) {
            int m = (l + r) / 2;
            if (m * m > x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }

    int mySqrt2(int x) {
        if (x == 0) return 0;
        int l = 2, r = x;
        while (l < r) {
            int mid = l + (r - l) / 2; // 避免溢出
            if ((long) mid * mid <= x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};

void test69() {
    cout << Solution69().mySqrt2(2147395599);
}
