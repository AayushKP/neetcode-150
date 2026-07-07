/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
      int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;

        // Check left subtree
        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;

        // Check right subtree
        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;

        // If current node is unbalanced, return -1
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Otherwise, return actual height
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
