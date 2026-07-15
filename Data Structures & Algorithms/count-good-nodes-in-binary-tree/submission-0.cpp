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
    int goodNodes(TreeNode* root) {
        // queue: traverse
        // record: 1. the maximum until current
        //          2. the count of good nodes
        int good_count = 0;
        if(!root)
            return good_count;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            auto& [node, curr_max] = q.front();
            if(node->val >= curr_max)
                good_count++;
            curr_max = max(curr_max, node->val);
            if(node->left)
                q.push({node->left, curr_max});
            if(node->right)
                q.push({node->right, curr_max});
            q.pop();
        }
        return good_count;
    }
};
