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
    bool wrap(TreeNode* root, int targetSum)
    {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(targetSum - root->val == 0) return true;
            else return false;
        }
        return wrap(root->left, targetSum - root->val) | wrap(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        else return wrap(root, targetSum);
    }
};