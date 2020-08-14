#include <iostream>
#include <vector>

using namespace std;

class Solution944 {
public:
    int minDeletionSize(vector<string> &A) {
        int n = A.size();
        if (n <= 1) {
            return 0;
        }

        int d_len = 0;
        int s_len = A[0].length();

        for (int i = 0; i < s_len; ++i) {
            for (int j = 1; j < n; ++j) {
                if (A[j - 1][i] > A[j][i]) {
                    ++d_len;
                    break;
                }
            }
        }
        return d_len;
    }
};

void test944() {
    string a[] = {"cba", "daf", "ghi"};
    vector<string> input(a, a + size(a));
    cout << Solution944().minDeletionSize(input) << endl;
}
