#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution1046 {
public:
    static int lastStoneWeight(vector<int> &stones) {
        priority_queue<int> max_heap; // 大顶堆
        for (const auto &s : stones) max_heap.emplace(s);
        for (int i = 0; i < stones.size() - 1; ++i) {
            int max1 = max_heap.top();
            max_heap.pop();
            int max2 = max_heap.top();
            max_heap.pop();
            max_heap.emplace(abs(max1 - max2));
        }
        return max_heap.top();
    }
};

void test1046() {
    int a[] = {2, 7, 4, 1, 8, 1};
    vector<int> input(a, a + size(a));
    cout << Solution1046::lastStoneWeight(input) << endl;
}
