#include <iostream>
#include <stack>
#include <queue>
#include "tree_node.h"

using namespace std;

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

    // 递归
    int rangeSumBST(TreeNode *root, int L, int R) {
        l = L;
        r = R;
        return sumOfNode(root);
    }

    // 回溯，优先遍历left
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
            if (n_v < R) dfs(node->right, L, R);
        }
    }

    // 以上都不考虑特性，此方法考虑BST（二叉查找树）特性：left < root < right
    int rangeSumBST3(TreeNode *root, int L, int R) {
        _sum = 0;
        dfs(root, L, R);
        return _sum;
    }

    // 队列，经典DFS
    int rangeSumBST4(TreeNode *root, int L, int R) {
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        int sum = 0;

        while (!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();
            int n_v = node->val;
            if (L <= n_v && n_v <= R) {
                sum += n_v;
            }

            if (node->left != nullptr) node_queue.push(node->left);
            if (node->right != nullptr) node_queue.push(node->right);
        }
        return sum;
    }

    // 队列，经典BFS
    int rangeSumBST5(TreeNode *root, int L, int R) {
        queue<TreeNode *> node_queue;
        node_queue.push(root);
        int sum = 0;

        while (!node_queue.empty()) {
            for (int i = 0; i < node_queue.size(); ++i) {
                TreeNode *node = node_queue.front();
                node_queue.pop();
                int n_v = node->val;
                if (L <= n_v && n_v <= R) {
                    sum += n_v;
                }

                if (node->left != nullptr) node_queue.push(node->left);
                if (node->right != nullptr) node_queue.push(node->right);
            }
        }
        return sum;
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
    cout << Solution938().rangeSumBST5(&root, 7, 15) << endl;
}
