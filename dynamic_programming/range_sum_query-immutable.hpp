#include <iostream>
#include <vector>

using namespace std;

// Time Limit Exceeded
class NumArray {
private:
    vector<int> _nums;
public:
    NumArray(vector<int> &nums) {
        _nums = nums;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; ++k) {
            sum += _nums[k];
        }
        return sum;
    }
};

class NumArray2 {
private:
    vector<int> sums;
public:
    NumArray2(vector<int> &nums) {
        int n = nums.size();
        if (n <= 0) return;
        sums = vector<int>(n);
        sums[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i <= 0) {
            return sums[j];
        }
        return sums[j] - sums[i - 1];
    }
};

class NumArray3 {
private:
    vector<int> sums;
public:
    NumArray3(vector<int> &nums) {
        sums.emplace_back(0);
        for (const auto& num : nums) {
            sums.emplace_back(sums.back() + num);
        }
    }

    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
void test303() {
    int a[] = {-2, 0, 3, -5, 2, -1};
    vector<int> input(a, a + size(a));
    auto *obj = new NumArray3(input);
    cout << obj->sumRange(0, 2) << endl;
    cout << obj->sumRange(2, 5) << endl;
    cout << obj->sumRange(0, 5) << endl;
}
