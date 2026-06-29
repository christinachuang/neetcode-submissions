class LRUCache {
public:
    LRUCache(int capacity) {
        limit = capacity;
    }
    
    int get(int key) {
        if(lookup.count(key)){
            int val = lookup[key]->second;
            order.splice(order.begin(), order, lookup[key]);
            lookup[key] = order.begin();
            return lookup[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(lookup.count(key)){
            order.splice(order.begin(), order, lookup[key]);
            lookup[key] = order.begin();
            order.front().second = value;
        }
        else{
            if(limit > 0 && order.size() == limit){
                int rm_key = std::prev(order.end())->first;
                order.pop_back();
                lookup.erase(rm_key);
            }
            order.push_front({key, value});
            lookup[key] = order.begin();
        }
    }
private:
    unordered_map<int, list<pair<int, int>>::iterator> lookup; // key, iter
    list<pair<int, int>> order; // {key, value}
    int limit = 0;
};
