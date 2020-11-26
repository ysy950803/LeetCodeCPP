#include <iostream>
#include <vector>

using namespace std;

class SolutionN {
public:
    static vector<bool> doSolution(vector<int> &input) {
        // return output
    }
};

void test69() {
    vector<int> input({1, 2, 3});
    vector<bool> output = SolutionN::doSolution(input);
    copy(output.begin(), output.end(), ostream_iterator<bool>(cout, " "));
}
