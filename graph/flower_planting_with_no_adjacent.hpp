#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1042 {
public:
    // Time Limit Exceeded
    vector<int> gardenNoAdj(int N, vector<vector<int>> &paths) {
        // [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]

        //    1 2 3 4
        // 1  0 0 0 0
        // 2  1 0 0 0
        // 3  1 1 0 0
        // 4  1 1 1 0

        vector<vector<int>> p_map(N + 1, vector<int>(N + 1, 0));
        for (const auto &path : paths) {
            int x = path[0];
            int y = path[1];
            if (x > y) swap(x, y);
            p_map[x][y] = 1;
        }

        int color;
        vector<int> colors(N + 1, paths.empty() ? 1 : 0);
        for (int x = 1; x < p_map.size(); ++x) {
            color = colors[x];

            for (int y = x + 1; y < p_map[x].size(); ++y) {
                if (p_map[x][y] == 1) {
                    if (colors[x] == 0) {
                        ++color;
                        colors[x] = color;
                    }
                    if (colors[y] == 0) {
                        ++color;
                        if (color == colors[x]) ++color;
                        if (color > 4) color = 1;
                        colors[y] = color;
                    } else if (colors[y] == colors[x]) {
                        ++color;
                        if (color > 4) color = 1;
                        colors[y] = color;
                    }
                }
            }
        }

        for (int &c : colors) if (c == 0) c = 1;
        return vector<int>(colors.begin() + 1, colors.end());
    }

    vector<int> gardenNoAdj2(int N, vector<vector<int>> &paths) {
        vector<int> result(N);
        vector<vector<int>> G(N);
        for (const auto &path : paths) {
            int x = path[0], y = path[1];
            G[x - 1].emplace_back(y - 1);
            G[y - 1].emplace_back(x - 1);
        }
        for (int i = 0; i < N; ++i) {
            unordered_set<int> candidates = {4, 3, 2, 1};
            for (const auto &j : G[i]) {
                candidates.erase(result[j]);
            }
            result[i] = *(candidates.cbegin()); // 这里set的begin从末位开始
        }
        return result;
    }
};

void test1042() {
    int a11[] = {1, 2};
    int a12[] = {3, 4};
    vector<int> v11(a11, a11 + size(a11));
    vector<int> v12(a12, a12 + size(a12));
    vector<vector<int> > v;
    v.push_back(v11);
    v.push_back(v12);
    vector<int> output = Solution1042().gardenNoAdj2(4, v);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
