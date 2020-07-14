#include <iostream>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution938 {
private:
    int l, r;
    int _sum;
public:
    int sumOfNode(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int v = node->val;
        return (l <= v && v <= r ? v : 0) + sumOfNode(node->left) + sumOfNode(node->right);
    }

    int rangeSumBST(TreeNode *root, int L, int R) {
        l = L;
        r = R;
        return sumOfNode(root);
    }

    int rangeSumBST2(TreeNode *root, int L, int R) {
        int sum = 0;
        if (root == nullptr) {
            return sum;
        }
        stack<TreeNode *> n_stack;
        TreeNode *node = root;

        while (node != nullptr) {
            int n_v = node->val;
            if (L <= n_v && n_v <= R) {
                sum += n_v;
            }

            if (node->right != nullptr) {
                n_stack.push(node->right);
            }
            if (node->left != nullptr) {
                node = node->left;
            } else {
                if (n_stack.empty()) {
                    node = nullptr;
                } else {
                    node = n_stack.top();
                    n_stack.pop();
                }
            }
        }
        return sum;
    }

    void dfs(TreeNode *node, int L, int R) {
        if (node != nullptr) {
            int n_v = node->val;
            if (L <= n_v && n_v <= R) _sum += n_v;
            if (L < n_v) dfs(node->left, L, R);
            if (n_v < R)dfs(node->right, L, R);
        }
    }

    // 以上都不考虑特性，此方法考虑BST(binary search tree)特性：left < root < right
    int rangeSumBST3(TreeNode *root, int L, int R) {
        _sum = 0;
        dfs(root, L, R);
        return _sum;
    }
};

void test938() {
    /*
     * root = [10,5,15,3,7,null,18]
     *    10
     *  5    15
     * 3 7 null 18
     */
    TreeNode t3_1(3), t3_2(7), t3_4(18);
    TreeNode t2_1(5, &t3_1, &t3_2), t2_2(15, nullptr, &t3_4);
    TreeNode root(10, &t2_1, &t2_2);
    cout << Solution938().rangeSumBST3(&root, 7, 15) << endl;
}
