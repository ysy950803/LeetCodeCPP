#include <iostream>
#include <vector>

using namespace std;

class Solution372 {
private:
    static const int MOD_N = 1337;
public:
    static int subPow(int a, int k) {
        a %= MOD_N;
        int res = 1;
        for (int _ = 0; _ < k; ++_) {
            res *= a;
            res %= MOD_N;
        }
        return res;
    }

    static int subPow2(int a, int k) {
        if (k == 0) return 1;
        a %= MOD_N;
        if (k % 2 == 0) {
            int sub = subPow2(a, k / 2);
            return (sub * sub) % MOD_N;
        } else {
            return (a * subPow2(a, k - 1)) % MOD_N;
        }
    }

    // a^[1, 2, 3] = a^3 * (a^[1, 2])^10
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int sub1 = subPow2(a, last);
        int sub2 = subPow2(superPow(a, b), 10);
        return (sub1 * sub2) % MOD_N;
    }
};

void test372() {
    int b[] = {3};
    vector<int> input(b, b + size(b));
    cout << Solution372().superPow(2, input) << endl;
}
