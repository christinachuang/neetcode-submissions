class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(tasks.empty())
            return 0;
        vector<int> count(26, 0);
        int max_item = 0, max_freq = 0;
        for(auto& x : tasks){
            count[x - 'A']++;
            max_freq = max(max_freq, count[x - 'A']);
        }
        for(auto& x : count){
            if(x == max_freq)
                max_item++;
        }
        return max((int)tasks.size(), (max_freq - 1) * (n + 1) + max_item);
    }
};