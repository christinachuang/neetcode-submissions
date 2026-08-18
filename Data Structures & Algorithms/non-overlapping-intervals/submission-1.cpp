class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), 
            [](const auto& a, const auto& b){return a[1] <= b[1];});
        int curr_endTime = intervals[0][1], remove = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < curr_endTime)
                remove++;
            else
                curr_endTime = intervals[i][1];
        }
        return remove;
    }
};

