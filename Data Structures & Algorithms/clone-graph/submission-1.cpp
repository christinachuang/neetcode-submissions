/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copy;
        Node* curr = node;
        return dfs(curr, copy);
    }
    Node* dfs(Node* curr, unordered_map<Node*, Node*>& copy){
        if(!curr)
            return nullptr;
            
        if(copy.count(curr))
            return copy[curr];
        
        Node* tmp = new Node(curr->val);
        copy[curr] = tmp;
        for(auto& adjacency : curr->neighbors)
            copy[curr]->neighbors.push_back(dfs(adjacency, copy));

        return copy[curr];
    }
};
