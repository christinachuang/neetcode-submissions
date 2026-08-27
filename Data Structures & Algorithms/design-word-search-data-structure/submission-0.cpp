struct TrieNode {
    vector<TrieNode*> neighbors = vector<TrieNode*>(26, nullptr);
    bool isEnd = false;
};
class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto& w : word){
            if(!curr->neighbors[w - 'a'])
                curr->neighbors[w - 'a'] = new TrieNode();
            curr = curr->neighbors[w - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int idx = 0;
        return dfs(curr, word, idx);
    }
private:
    TrieNode* root = nullptr;
    bool dfs(TrieNode* curr, string& word, int idx){
        if(idx == word.size())
            return curr->isEnd;
        char c = word[idx];
        bool found = false;
        if(c == '.'){
            for(auto& neighbor : curr->neighbors){
                if(neighbor && dfs(neighbor, word, idx + 1))
                    found = true;
            }   
        }
        else if(!curr->neighbors[word[idx] - 'a'])
            return false;
        else
            found = dfs(curr->neighbors[c - 'a'], word, idx + 1);
        return found;
    }
};
