class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Lookup[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!Lookup.count(key) || Lookup[key].empty())
            return "";
        int left = 0, right = Lookup[key].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            auto& [t, v] = Lookup[key][mid];
            if(t == timestamp)
                return v;
            else if(t > timestamp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left - 1 >= 0 ? Lookup[key][left - 1].second : "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> Lookup;
};
