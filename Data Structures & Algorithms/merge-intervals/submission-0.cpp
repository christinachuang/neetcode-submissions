class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals
        // loop and merge
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end());
        int curr_begin, curr_end;
        int idx = 0;
        while(idx < intervals.size()){
            curr_begin = intervals[idx][0];
            curr_end = intervals[idx][1];
            idx++;
            while(idx < intervals.size() && intervals[idx][0] <= curr_end){
                curr_begin = min(curr_begin, intervals[idx][0]);
                curr_end = max(curr_end, intervals[idx][1]);
                idx++;
            }
            output.push_back({curr_begin, curr_end});
        }
        return output;
    }
};
