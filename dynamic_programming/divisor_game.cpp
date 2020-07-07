#include <iostream>
#include <unordered_map>

using namespace std;

class Solution1025 {
public:
    static bool divisorGame(int N) {
        unordered_map<int, int> dp;
        return memoization(N, &dp);
    }

    static bool divisorGame2(int N) {
        return N % 2 == 0;
    }

private:
    static bool memoization(int N, unordered_map<int, int> *dp) {
        if (N == 1) {
            return false;
        }
        if (!dp->count(N)) {
            bool result = false;
            for (int i = 1; i * i <= N; ++i) {
                if (N % i == 0) {
                    if (!memoization(N - i, dp)) {
                        result = true;
                        break;
                    }
                }
            }
            (*dp)[N] = result;
        }
        return (*dp)[N];
    }
};

void test1025() {
    bool result = Solution1025::divisorGame(10);
    cout << result << endl;
}
