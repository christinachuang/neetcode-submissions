struct Trie {
    vector<Trie*> neighbors = vector<Trie*>(26, nullptr);
    bool isEnd = false;
};
class PrefixTree {
public:
    PrefixTree() {
        root = new Trie();
    }
    
    void insert(string word) {
        Trie* curr = root;
        for(const auto& w : word){
            if(!curr->neighbors[w - 'a'])
                curr->neighbors[w - 'a'] = new Trie();
            curr = curr->neighbors[w - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Trie* curr = root;
        for(const auto& w : word){
            if(!curr->neighbors[w - 'a'])
                return false;
            curr = curr->neighbors[w - 'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = root;
        for(const auto& w : prefix){
            if(!curr->neighbors[w - 'a'])
                return false;
            curr = curr->neighbors[w - 'a'];
        }
        return true;
    }
private:
    Trie* root;
};

