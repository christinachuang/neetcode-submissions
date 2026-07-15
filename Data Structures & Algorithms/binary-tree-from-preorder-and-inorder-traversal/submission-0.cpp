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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder: mid/left/right
        // inorder: left/mid/right
        // find mid with preorder -> find left subtree with inorder
        // record left and right range
        if(preorder.empty() || inorder.empty())
            return nullptr;
        return RebuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* RebuildTree(vector<int>& preorder, vector<int>& inorder,
        int pl, int pr, int il, int ir){
            if(pl > pr || il > ir)
                return nullptr;
            TreeNode* root = new TreeNode(preorder[pl]);
            int il_r = il;
            while(il_r < ir && inorder[il_r] != preorder[pl])
                il_r++; // inorder[il_r] == preorder[pl]
            int left = il_r - il;
            root->left = RebuildTree(preorder, inorder, pl + 1, pl + left, il, il_r - 1);
            root->right = RebuildTree(preorder, inorder, pl + left + 1, pr, il_r + 1, ir);
            return root;
        }
};
