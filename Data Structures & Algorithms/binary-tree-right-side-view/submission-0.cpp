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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        if(!root)
            return output;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int curr_size = q.size();
            for(int i = 0; i < curr_size; i++){
                if(q.front()->left)
                    q.push(q.front()->left);
                if(q.front()->right)
                    q.push(q.front()->right);
                if(i == curr_size - 1)
                    output.push_back(q.front()->val);
                q.pop();
            }
        }
        return output;
    }
};
