#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution387 {
public:
    int firstUniqChar(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < s.length(); ++j) {
                if (s[i] == s[j]) {
                    ++count;
                }
                if (count > 1) {
                    count = 0;
                    break;
                }
            }
            if (count == 1) {
                return i;
            }
        }
        return -1;
    }

    int firstUniqChar2(string s) {
        unordered_map<char, bool> dic;
        for (char c : s) {
            dic[c] = dic.find(c) == dic.end();
        }
        for (int i = 0; i < s.length(); ++i) {
            if (dic[s[i]]) return i;
        }
        return -1;
    }

    int firstUniqChar3(string s) {
        vector<int> keys;
        unordered_map<char, bool> dic;
        for (int i = 0; i < s.length(); ++i) {
            if (dic.find(s[i]) == dic.end()) {
                dic[s[i]] = true;
                keys.push_back(i);
            } else {
                dic[s[i]] = false;
            }
        }
        for (int key : keys) {
            if (dic[s[key]]) return key;
        }
        return -1;
    }
};

void test387() {
    string input = "loveleetcode";
    cout << Solution387().firstUniqChar3(input) << endl;
}
