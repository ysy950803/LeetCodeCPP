#include <iostream>

using namespace std;

void spread();

class Solution1486 {
public:
    int xorOperation(int n, int start) {
        int xor_sum = start;
        for (int i = 1; i < n; ++i) {
            xor_sum ^= (start + (i << 1));
        }
        return xor_sum;
    }
};

void test1486() {
    int output = Solution1486().xorOperation(10, 5);
    cout << output << endl;

    spread();
}

// 引申，<异或和>的规律
void spread() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    // 3  0 4 1 7  0 8 1 11  0 12 1 15 0 16 1 19
    // n=3, 0   n=7, 0      n=4m-1, 0
    // n=4, 4   n=8, 8      n=4m, 4m
    // n=5, 1   n=9, 1      n=4m+1, 1
    // n=6, 7   n=10, 11    n=4m+2, 4m+3
    int xor_5_sum = a[0];
    for (int j = 1; j < size(a); ++j) {
        xor_5_sum ^= a[j];
        cout << xor_5_sum << " ";
    }
    cout << endl;

    for (int i = 1; i < size(a); ++i) {
        if (i == 1) {
            cout << 3 << " ";
        } else if (a[i] % 4 == 0) {
            cout << a[i] << " ";
        } else if (a[i] % 4 == 1) {
            cout << 1 << " ";
        } else if (a[i] % 4 == 2) {
            cout << a[i - 2] + 3 << " ";
        } else {
            cout << 0 << " ";
        }
    }
}
