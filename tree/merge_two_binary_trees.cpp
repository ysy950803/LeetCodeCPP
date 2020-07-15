#include "tree_node.h"

using namespace std;

class Solution617 {
public:
    void dfs(TreeNode *t1, TreeNode *t2) {
        if (t1->left != nullptr) {
            if (t2->left != nullptr) {
                t1->left->val += t2->left->val;
                dfs(t1->left, t2->left);
            }
        } else {
            if (t2->left != nullptr) {
                t1->left = t2->left;
            }
        }
        if (t1->right != nullptr) {
            if (t2->right != nullptr) {
                t1->right->val += t2->right->val;
                dfs(t1->right, t2->right);
            }
        } else {
            if (t2->right != nullptr) {
                t1->right = t2->right;
            }
        }
    }

    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 != nullptr && t2 != nullptr) {
            t1->val += t2->val;
            dfs(t1, t2);
            return t1;
        }
        return t1 == nullptr ? t2 : t1;
    }

    TreeNode *mergeTrees2(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr) return t2;
        if (t2 == nullptr) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

/*
Input:
	Tree 1                     Tree 2
          1                         2
         / \                       / \
        3   2                     1   3
       /                           \   \
      5                             4   7
Output:
Merged tree:
	     3
	    / \
	   4   5
	  / \   \
	 5   4   7
 */
void test617() {
    TreeNode t_a_3_1(5);
    TreeNode t_a_2_1(3, &t_a_3_1, nullptr), t_a_2_2(2);
    TreeNode root_a(1, &t_a_2_1, &t_a_2_2);

    TreeNode t_b_3_2(4), t_b_3_4(7);
    TreeNode t_b_2_1(1, nullptr, &t_b_3_2), t_b_2_2(3, nullptr, &t_b_3_4);
    TreeNode root_b(2, &t_b_2_1, &t_b_2_2);

    Solution617().mergeTrees(&root_a, &root_b);
}
