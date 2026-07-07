class LRUCache {
public:
    LRUCache(int capacity): limit(capacity){} 
    int get(int key){
        // check if lookup exist key or return -1
        // get也要更新！！
        if(lookup.count(key)){
            list<int>::iterator it = lookup[key].second;
            cache.erase(it);
            cache.push_front(key);
            lookup[key].second = cache.begin();
            return lookup[key].first;
        }
        else
            return -1;
    }
    void put(int key, int value){
        // not exist -> cache.size() >= limit?
        if(!lookup.count(key)){
            if(cache.size() == limit){
                int rm_key = cache.back();
                cache.erase(lookup[rm_key].second);
                lookup.erase(lookup.find(rm_key));
            }
            cache.push_front(key);
            lookup[key] = {value, cache.begin()};
        }
        else{
            cache.erase(lookup[key].second);
            cache.push_front(key);
            lookup[key] = {value, cache.begin()};
        }
        // exist -> modify lookup[key], cache[key](erase + push_front()))
    }
private:
    unordered_map<int, pair<int, list<int>::iterator>> lookup; // key: {val, it}
    list<int> cache; // key
    int limit;
};
