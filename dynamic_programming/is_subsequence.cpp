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
            // 大串剩余部分已不足校验子串，直接false
            if (s_n - cursor > t_n - 1 - i) {
                return false;
            }
        }
        return false;
    }
};

void test392() {
    string s = "";
    string t = "ahbgdc";
    bool output = Solution392::isSubsequence2(s, t);
    cout << output << endl;
}
