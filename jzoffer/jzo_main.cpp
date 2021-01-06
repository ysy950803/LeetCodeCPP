#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// LC：面试题4
// NC：JZ1
class Solution1 {
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

// LC：剑指 Offer 06
// NC：JZ3
class Solution2 {
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

// LC：剑指 Offer 22
// NC：JZ14
class Solution3 {
public:
    // 双指针滑动
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pre = head;
        for (int i = 0; i < k - 1; ++i) {
            head = head->next;
        }
        while (head->next) {
            pre = pre->next;
            head = head->next;
        }
        return pre;
    }
};

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x) {}
};

// LC：剑指 Offer 07
// NC：JZ4
class Solution9 {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        auto *n = new TreeNode(preorder[0]);
        if (preorder.size() == 1) {
            return n;
        }
        int root_idx = distance(inorder.cbegin(), find(inorder.cbegin(), inorder.cend(), n->val));
        int left_size = root_idx;
        vector<int> l_pre(preorder.cbegin() + 1, preorder.cbegin() + 1 + left_size);
        vector<int> l_in(inorder.cbegin(), inorder.cbegin() + root_idx);
        vector<int> r_pre(preorder.cbegin() + left_size + 1, preorder.cend());
        vector<int> r_in(inorder.cbegin() + root_idx + 1, inorder.cend());
        n->left = buildTree(l_pre, l_in);
        n->right = buildTree(r_pre, r_in);
        return n;
    }

    void bfs_print(TreeNode *node) {
        if (!node) return;
        queue<TreeNode *> q({node});
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                TreeNode *n = q.front();
                q.pop();
                cout << n->val << endl;
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
    }
};

// LC：剑指 Offer 34
// NC：JZ24
class Solution14 {
private:
    vector<vector<int>> paths;
    vector<int> path;
public:
    void visit(TreeNode *root, int tar) {
        if (!root) return;
        path.push_back(root->val);
        tar -= root->val;
        if (tar == 0 && !root->left && !root->right) {
            vector<int> tmp_path(path);
            paths.push_back(tmp_path);
        }
        visit(root->left, tar);
        visit(root->right, tar);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        visit(root, sum);
        return paths;
    }
};

class Solution15 {
public:
    // LC：剑指 Offer 36（双向循环链表）
    TreeNode *treeToDoublyList(TreeNode *root) {
        if (!root) return nullptr;
        TreeNode *pre_head = treeToDoublyList(root->left);
        TreeNode *nxt_head = treeToDoublyList(root->right);

        if (pre_head) {
            TreeNode *pre_tail = pre_head->left;
            pre_tail->right = root;
            root->left = pre_tail;
        } else {
            pre_head = root;
        }

        TreeNode *nxt_tail;
        if (nxt_head) {
            nxt_tail = nxt_head->left;
            nxt_head->left = root;
            root->right = nxt_head;
        } else {
            nxt_tail = root;
        }

        pre_head->left = nxt_tail;
        nxt_tail->right = pre_head;
        return pre_head;
    }

    // 必须初始化nullptr，不然AC不了
    TreeNode *prev_head = nullptr;
    TreeNode *prev_tail = nullptr;

    // NC：JZ26（双向链表，无循环，首尾不相连）
    TreeNode *Convert(TreeNode *root) {
        if (!root) return nullptr;
        Convert(root->left);
        if (prev_head) {
            prev_tail->right = root;
            root->left = prev_tail;
        } else {
            prev_head = root;
        }
        prev_tail = root;
        Convert(root->right);
        return prev_head;
    }

    void inOrderConvert(TreeNode *root) {
        if (!root)
            return;
        inOrderConvert(root->left);
        root->left = prev_tail;
        if (prev_tail)
            prev_tail->right = root;
        prev_tail = root;
        inOrderConvert(root->right);
    }

    TreeNode *Convert2(TreeNode *pRootOfTree) {
        inOrderConvert(pRootOfTree);
        while (prev_tail && prev_tail->left)
            prev_tail = prev_tail->left;
        return prev_tail;
    }
};

// LC：剑指 Offer 55 - I
// NC：JZ38
class Solution16 {
public:
    int maxDepth(TreeNode *root) {
        return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

// LC：剑指 Offer 55 - II
// NC：JZ39
class Solution17 {
public:
    int maxDepth(TreeNode *root) {
        return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1
               && isBalanced(root->left) && isBalanced(root->right);
    }
};

// LC：剑指 Offer 28
// NC：JZ58
class Solution19 {
public:
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right || left->val != right->val) return false;
        return symmetric(left->left, right->right)
               && symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return symmetric(root->left, root->right);
    }
};

// LC：剑指 Offer 32 - III
// NC：JZ59
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q({root});
        int q_size;
        TreeNode *n;
        vector<int> line;
        bool ltr = true;
        while (!q.empty()) {
            q_size = q.size();
            line.clear();
            for (int i = 0; i < q_size; ++i) {
                n = q.front();
                q.pop();
                if (!n) continue;
                if (ltr) {
                    line.emplace_back(n->val);
                } else {
                    line.emplace(line.cbegin(), n->val);
                }
                if (n->left) q.emplace(n->left);
                if (n->right) q.emplace(n->right);
            }
            if (!line.empty()) {
                res.emplace_back(line);
                ltr = !ltr;
            }
        }
        return res;
    }
};

// LC：剑指 Offer 32 - II
// NC：JZ60
class Solution21 {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q({root});
        int q_size;
        TreeNode *n;
        vector<int> line;
        while (!q.empty()) {
            q_size = q.size();
            line.clear();
            for (int i = 0; i < q_size; ++i) {
                n = q.front();
                q.pop();
                if (!n) continue;
                line.emplace_back(n->val);
                if (n->left) q.emplace(n->left);
                if (n->right) q.emplace(n->right);
            }
            if (!line.empty()) res.emplace_back(line);
        }
        return res;
    }
};

void quick_sort(vector<int> &arr, int left, int right) {
    if (left >= right) return;

    int mid = arr[left];
    int i = left, j = right;

    while (i < j) {
        while (i < j && mid <= arr[j]) {
            --j;
        }
        arr[i] = arr[j];
        while (i < j && mid >= arr[i]) {
            ++i;
        }
        arr[j] = arr[i];
    }
    arr[i] = mid;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

int main() {
//    vector<vector<int>> m({{1,  4,  7,  11, 15},
//                           {2,  5,  8,  12, 19},
//                           {3,  6,  9,  16, 22},
//                           {10, 13, 14, 17, 24},
//                           {18, 21, 23, 26, 30}
//                          });
//    cout << Solution1().findNumberIn2DArray(m, 32);
//
//    auto n3 = ListNode(3, nullptr);
//    auto n2 = ListNode(2, &n3);
//    auto head = ListNode(1, &n2);
//    vector<int> output = Solution2().reversePrint(&head);
//    copy(output.begin(), output.end(), ostream_iterator<int>(cout, " "));

//    vector<int> pre({1, 2, 3, 4, 5, 6, 7});
//    vector<int> in({3, 2, 4, 1, 6, 5, 7});
//    Solution9().bfs_print(Solution9().buildTree(pre, in));

    vector<int> arr({1, 2, 3, 4, 5, 6, 7});
    quick_sort(arr, 0, arr.size() - 1);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
