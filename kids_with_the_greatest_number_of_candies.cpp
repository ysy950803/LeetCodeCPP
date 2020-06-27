#include <iostream>
#include <vector>

using namespace std;

class Solution1431 {
public:
    static vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies) {
        int len = candies.size();
        vector<int> sort_c(candies);
        sort(begin(sort_c), end(sort_c));
        int max = sort_c[len - 1];
        bool b[len];
        for (int i = 0; i < len; ++i) {
            b[i] = candies[i] + extraCandies >= max;
        }
        return vector<bool>(b, b + len);
    }

    // BEST
    static vector<bool> kidsWithCandies2(vector<int> &candies, int extraCandies) {
        const auto &max_num = *max_element(cbegin(candies), cend(candies));
        vector<bool> result;
        transform(cbegin(candies), cend(candies), back_inserter(result),
                  [&extraCandies, &max_num](const auto &x) {
                      return x + extraCandies >= max_num;
                  });
        return result;
    }
};

void test1431() {
    int a[] = {2, 3, 5, 1, 3};
    vector<int> input(a, a + size(a));
    vector<bool> output = Solution1431::kidsWithCandies2(input, 3);
    copy(output.begin(), output.end(), ostream_iterator<bool>(cout, " "));
}
