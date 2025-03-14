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
    TreeNode* wrap(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& elementIndex, int left, int right, int& i)
    {
        if(left > right || i >= preorder.size()) return NULL;
        else
        {
            int rootVal = preorder[i];
            int idx = elementIndex[rootVal];
            TreeNode* root = new TreeNode(rootVal);
            i++;
            root->left  = wrap(preorder, inorder, elementIndex, left, idx - 1, i);
            root->right = wrap(preorder, inorder, elementIndex, idx + 1, right, i);
            return root;
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); // inordersize will also be n
        unordered_map<int, int> elementIndex; // we did this so that it's easy to split array
        for(int i = 0; i < n; ++i)
        {
            elementIndex[inorder[i]] = i;
        }
        int start = 0;
        return wrap(preorder, inorder, elementIndex, 0, n - 1, start);
    }
};
