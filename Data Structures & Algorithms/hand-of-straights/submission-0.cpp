class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        if(size % groupSize != 0)
            return false;
        int groups = size / groupSize;
        
        map<int, int> lookup;
        for(const auto& x : hand)
            lookup[x]++;
        for(int round = 0; round < groups; round++){
            int start_val = lookup.begin()->first;
            for(int curr = 0; curr < groupSize; curr++){
                int target = start_val + curr;
                if(!lookup.count(target) || lookup[target] == 0)
                    return false;
                lookup[target]--;
                if(lookup[target] == 0)
                    lookup.erase(target);
            }
        }
        return true;
    }
};
