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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // use a queue for traverse each level
        vector<vector<int>> output;
        if(!root)
            return output;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> curr;
            int curr_size = q.size();
            for(int i = 0; i < curr_size; i++){
                TreeNode* front = q.front();
                curr.emplace_back(front->val);
                if(front->left)
                    q.emplace(front->left);
                if(front->right)
                    q.emplace(front->right);
                q.pop();
            }
            output.push_back(curr);
        }
        return output;
    }
};


