#include <iostream>
#include <unordered_map>

using namespace std;

class Solution1025 {
public:
    bool divisorGame(int N) {
        unordered_map<int, int> dp;
        return memoization(N, &dp);
    }

    // BEST
    // 1. if we get an even, we can choose x = 1
    //    to make the opponent always get an odd
    // 2. if the opponent gets an odd, he can only choose x = 1 or other odds
    //    and we can still get an even
    // 3. at the end, the opponent can only choose x = 1 and we win
    // 4. in summary, we win if only if we get an even and
    //    keeps even until the opponent loses
    bool divisorGame2(int N) {
        return N % 2 == 0;
    }

private:
    // 记忆化搜索
    bool memoization(int N, unordered_map<int, int> *dp) {
        if (N == 1) {
            return false;
        }
        if (!dp->count(N)) {
            bool result = false;
            for (int i = 1; i * i <= N; ++i) {
                if (N % i == 0) {
                    // 递归校验下一步，若对方输，己方便能赢
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
    bool result = Solution1025().divisorGame2(10);
    cout << result << endl;
}
