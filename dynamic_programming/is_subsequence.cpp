#include <iostream>
#include <vector>

using namespace std;

class Solution392 {
public:
    static bool isSubsequence(string s, string t) {
        int count = 0, cursor = 0;
        bool add;
        for (char a : s) {
            add = false;
            for (int j = cursor; j < (int) t.size(); ++j) {
                if (a == t[j]) {
                    cursor = j + 1;
                    ++count;
                    add = true;
                    break;
                }
            }
            if (!add) {
                return false;
            }
        }
        return s.size() == count;
    }

    // 双指针，和第一种解法类似
    static bool isSubsequence2(string s, string t) {
        int s_n = s.size();
        if (s_n == 0) return true;

        int t_n = t.size();
        int cursor = 0;
        char move_c = s[cursor];

        for (int i = 0; i < t_n; ++i) {
            if (t[i] == move_c) {
                if (cursor >= s_n - 1) {
                    return true;
                }
                move_c = s[++cursor];
            }
            // 大串剩余部分已不足校验子序列，直接false
            if (s_n - cursor > t_n - 1 - i) {
                return false;
            }
        }
        return false;
    }

    // 状态转移：dp[i][j]是一个bool矩阵，矩阵元素表示 长度为i的s的子序列 是否为 长度为j的t的子序列 的子序列
    static bool isSubsequence3(string s, string t) {
        int s_n = s.size(), t_n = t.size();
        bool dp[s_n + 1][t_n + 1];
        // dp[i][0]表示t串长度为0，故必然不为子序列
        for (int i = 0; i <= s_n; ++i) {
            dp[i][0] = false;
        }
        // dp[0][j]表示s串长度为0，故必然为子序列
        for (int j = 0; j <= t_n; ++j) {
            dp[0][j] = true;
        }

        for (int i = 1; i <= s_n; ++i) {
            for (int j = 1; j <= t_n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    // s[i]=t[j]时，表示s的子序列末位与t的子序列末位相等，把其二者删掉，剩余的2个子序列仍有包含关系
                    // 即dp[i - 1][j - 1]仍为true
                    dp[i][j] = dp[i - 1][j - 1]; // 始终为1
                } else {
                    // 反之，若二者末位不相等，还有其他可能的包含关系，则只能是t的长度-1（例：s=ab，t=abc）
                    dp[i][j] = dp[i][j - 1]; // 有1有0
                }
            }
        }
        return dp[s_n][t_n];
    }
};

void test392() {
    string s = "abc";
    string t = "ahbgdce";
    bool output = Solution392::isSubsequence3(s, t);
    cout << output << endl;
}
