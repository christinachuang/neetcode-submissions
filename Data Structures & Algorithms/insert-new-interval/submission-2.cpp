class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // search a place for newInterval -> binary search
        // create a new vector for output
        // loop intervals, and put non-overlapping results into the output vector
        //[[1,2],[3,5],[6,7],[9,10]]
        BinarySearch(intervals, newInterval);
        vector<vector<int>> output;
        int curr_begin, curr_end;
        for(int i = 0; i < intervals.size(); i++){
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
            int idx = i + 1;
            while(idx < intervals.size() && intervals[idx][0] <= curr_end){
                curr_begin = min(curr_begin, intervals[idx][0]);
                curr_end = max(curr_end, intervals[idx][1]);
                idx++;
            }
            output.push_back({curr_begin, curr_end});
            i = idx - 1;
        }
        return output;
    }
    void BinarySearch(vector<vector<int>>& intervals, vector<int>& newInterval){
        int left = 0, right = intervals.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(intervals[mid][0] < newInterval[0])
                left = mid + 1;
            else
                right = mid - 1;
        }
        intervals.insert(intervals.begin() + left, newInterval);
    }
};
