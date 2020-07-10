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

    // 矩阵快速幂
    // Fibo证明：https://zh.wikipedia.org/wiki/%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0%E5%88%97
    // 下面全部用二级指针处理，啊！太痛苦了！还是vector大法好！
    static int climbStairs2(int n) {
        int **q;
        q = new int *[2];
        int q_v[2][2] = {{1, 1},
                         {1, 0}};
        for (int i = 0; i < 2; ++i) {
            q[i] = new int[2];
            for (int j = 0; j < 2; ++j) {
                q[i][j] = q_v[i][j];
            }
        }

        int **res = pow(q, n);
        return res[0][0];
    }

    static int **pow(int **a, int n) {
        int **ret;
        ret = new int *[2];
        int ret_v[2][2] = {{1, 0},
                           {0, 1}};
        for (int i = 0; i < 2; ++i) {
            ret[i] = new int[2];
            for (int j = 0; j < 2; ++j) {
                ret[i][j] = ret_v[i][j];
            }
        }

        while (n > 0) {
            if ((n & 1) == 1) {
                ret = multiply(ret, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return ret;
    }

    static int **multiply(int **a, int **b) {
        int **c;
        c = new int *[2];
        for (int i = 0; i < 2; i++) {
            c[i] = new int[2];
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }
};

void test70() {
    cout << Solution70::climbStairs2(45) << endl;

//    int a[3] = {1, 2, 3};
//    int *p1 = a;
//    int (*p2)[3] = &a;
//    cout << "a = " << a << endl;
//    cout << "a+1 = " << a + 1 << endl; // 4
//    cout << "&a = " << &a << endl;
//    cout << "&a+1 = " << &a + 1 << endl; // 4 * 3
}
