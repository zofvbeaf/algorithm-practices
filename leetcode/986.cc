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
  vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    vector<Interval> ans;
    for(int i = 0; i < A.size(); ++i) {
      for(int j = 0; j < B.size(); ++j) {
        if(B[j].start > A[i].end) break;
        else if(A[i].start > B[j].end) continue;
        else if(B[j].start == A[i].end) 
          ans.push_back(Interval(B[j].start, B[j].start));
        else if(B[j].end == A[i].start) 
          ans.push_back(Interval(A[i].start, A[i].start));
        else if(B[j].start <= A[i].start && A[i].end <= B[j].end)
          ans.push_back(Interval(A[i].start, A[i].end));
        else if(A[i].start <= B[j].start && B[j].end <= A[i].end)
          ans.push_back(Interval(B[j].start, B[j].end));
        else if(A[i].start <= B[j].start && A[i].end <= B[j].end)
          ans.push_back(Interval(B[j].start, A[i].end));
        else if(B[j].start <= A[i].start && B[j].end <= A[i].end)
          ans.push_back(Interval(A[i].start, B[j].end));
      }
    }
    return ans;
  }
};
