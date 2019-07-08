/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
      vector<Interval> ans; 
      bool is_inserted = false;
      for(int i = 0; i < intervals.size(); ++i) { 
        if(!is_inserted) {
          if(intervals[i].end < newInterval.start) ans.push_back(intervals[i]);
          else if(intervals[i].end == newInterval.start) {
            intervals[i].end = newInterval.end;
            ans.push_back(intervals[i]);
            is_inserted = true;
          }
          else {
            if(newInterval.end < intervals[i].start) ans.push_back(newInterval);
            else {
              intervals[i].start = min(newInterval.start, intervals[i].start);
              intervals[i].end = max(newInterval.end, intervals[i].end);
            }
            ans.push_back(intervals[i]);
            is_inserted = true;
          }
        }
        else {
          if(!ans.empty() && intervals[i].start <= ans.back().end) 
            ans.back().end = max(ans.back().end, intervals[i].end);
          else 
            ans.push_back(intervals[i]);
        }
      }
      if(!is_inserted) ans.push_back(newInterval);
      return ans;
    }
};


