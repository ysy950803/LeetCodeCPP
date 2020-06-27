#include <iostream>
#include <vector>

using namespace std;

class SolutionN {
public:
    static vector<bool> doSolution(vector<int> &input) {
        // return output
    }
};

void testN() {
    int a[] = {};
    vector<int> input(a, a + size(a));
    vector<bool> output = SolutionN::doSolution(input);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
}
