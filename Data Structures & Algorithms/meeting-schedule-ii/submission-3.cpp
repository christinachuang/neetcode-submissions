/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), 
            [](const auto& a, const auto& b){return a.start < b.start;});
        priority_queue<int, vector<int>, greater<int>> end_pq;
        for(auto& interval : intervals){
            if(!end_pq.empty() && interval.start >= end_pq.top())
                end_pq.pop();
            end_pq.push(interval.end);
        }
        return end_pq.size();
    }
};

