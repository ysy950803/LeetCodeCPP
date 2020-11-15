#include <iostream>
#include <vector>

using namespace std;

class Solution4 {
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        for (const auto &row : matrix) {
            if (target > row.back()) continue;
            if (target < row.front()) continue;
            for (const auto &i : row) {
                if (i == target) return true;
            }
        }
        return false;
    }
};

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution6 {
public:
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *cur = head;
        ListNode *old_head;
        while (cur->next) {
            old_head = head;
            head = cur->next;
            cur->next = cur->next->next;
            head->next = old_head;
        }
        return head;
    }

    vector<int> reversePrint(ListNode *head) {
        if (head == nullptr) return {};
        if (head->next == nullptr) return {head->val};
        vector<int> lst = {};
        ListNode *cur = reverse(head);
        while (cur) {
            lst.push_back(cur->val);
            cur = cur->next;
        }
        return lst;
    }
};

int main() {
    vector<vector<int>> m({{1,  4,  7,  11, 15},
                           {2,  5,  8,  12, 19},
                           {3,  6,  9,  16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}
                          });
//    cout << Solution4().findNumberIn2DArray(m, 32);

    auto n3 = ListNode(3, nullptr);
    auto n2 = ListNode(2, &n3);
    auto head = ListNode(1, &n2);
    vector<int> output = Solution6().reversePrint(&head);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
