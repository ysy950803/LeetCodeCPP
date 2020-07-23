#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Time Limit Exceeded
class KthLargest {
private:
    const int _k;
    priority_queue<int> max_heap;
public:
    KthLargest(int k, vector<int> &nums) : _k(k) {
        for (const auto &n : nums) max_heap.emplace(n);
    }

    int add(int val) {
        max_heap.emplace(val);
        vector<int> tmp;
        for (int i = 0; i < _k - 1; ++i) {
            tmp.emplace_back(max_heap.top());
            max_heap.pop();
        }
        int ans = max_heap.top();
        for (const auto &t : tmp) max_heap.emplace(t);
        return ans;
    }
};

// 小顶堆
class KthLargest2 {
private:
    const int _k;
    priority_queue<int, vector<int>, greater<>> min_heap;
public:
    KthLargest2(int k, vector<int> &nums) : _k(k) {
        for (const auto &n : nums) min_heap.emplace(n);
    }

    int add(int val) {
        min_heap.emplace(val);
        int n = min_heap.size() - _k;
        for (int i = 0; i < n; ++i) min_heap.pop();
        return min_heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
void test703() {
    int k = 3;
    int a[] = {4, 5, 8, 2};
    vector<int> input(a, a + size(a));
    KthLargest2 *obj = new KthLargest2(k, input);
    cout << obj->add(3) << endl; // returns 4
    cout << obj->add(5) << endl; // returns 5
    cout << obj->add(10) << endl; // returns 5
    cout << obj->add(9) << endl; // returns 8
    cout << obj->add(4) << endl; // returns 8
}
