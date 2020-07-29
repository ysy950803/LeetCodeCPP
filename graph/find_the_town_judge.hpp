#include <iostream>
#include <vector>

using namespace std;

class Solution997 {
public:
    static int findJudge(int N, vector<vector<int>> &trust) {
        int i_a[N + 1], o_a[N + 1]; // 入度，出度，题外话：a表示array的意思
        for (int i = 1; i < N + 1; ++i) {
            i_a[i] = 0;
            o_a[i] = 0;
        }
        for (const auto &t : trust) {
            o_a[t[0]] += 1;
            i_a[t[1]] += 1;
        }
        for (int i = 1; i < N + 1; ++i) {
            // 出度为0，入度为总人数除去自己
            if (o_a[i] == 0 && i_a[i] == N - 1) return i;
        }
        return -1;
    }

    static int findJudge2(int N, vector<vector<int>> &trust) {
        int io_a[N + 1]; // 出入度
        for (int i = 1; i <= N; ++i) io_a[i] = 0;
        for (const auto &t : trust) io_a[t[0]]--, io_a[t[1]]++;
        for (int i = 1; i <= N; ++i) if (io_a[i] == N - 1) return i;
        return -1;
    }
};

void test997() {
    int a11[] = {1, 3};
    int a12[] = {2, 3};
    vector<int> v11(a11, a11 + size(a11));
    vector<int> v12(a12, a12 + size(a12));
    vector<vector<int> > v;
    v.push_back(v11);
    v.push_back(v12);
    cout << Solution997::findJudge2(3, v);
}
