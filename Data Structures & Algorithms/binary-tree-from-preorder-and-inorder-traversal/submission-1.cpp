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
        unordered_map<int, int> inorder_map;
        for(int i = 0; i < inorder.size(); i++)
            inorder_map[inorder[i]] = i;
        return RebuildTree(preorder, inorder_map, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* RebuildTree(vector<int>& preorder, unordered_map<int, int>& inorder_map,
        int pl, int pr, int il, int ir){
            if(pl > pr || il > ir)
                return nullptr;
            TreeNode* root = new TreeNode(preorder[pl]);
            // preorder: mid/left/right
            // inorder: left/mid/right
            int mid_idx = inorder_map[preorder[pl]];
            int left = mid_idx - il;
            root->left = RebuildTree(preorder, inorder_map, pl + 1, pl + left, il, mid_idx - 1);
            root->right = RebuildTree(preorder, inorder_map, pl + left + 1, pr, mid_idx + 1, ir);
            return root;
        }
};
