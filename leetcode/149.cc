/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
	int maxPoints(vector<Point>& points) {
	  int ans = 0;
	  unordered_map<double, unordered_map<double, int>> cnt;
	  unordered_map<int, int> inf_cnt;
	  unordered_map<int, unordered_map<int, int>> point_cnt;
	  unordered_map<double, unordered_map<double, bool>> cnt_flag;
	  unordered_map<int, bool> inf_flag;
	  if(points.size() < 2) return 0;
		for(int i = 1; i < points.size(); ++i) {
      int pcnt = 0;
      if(point_cnt.count(points[i].x) && point_cnt[points[i].x].count(points[i].y)) 
        pcnt = point_cnt[points[i].x][points[i].y];
      cnt_flag.clear();
      inf_flag.clear();
	    for(int j = 0; j < i; ++j) {
	      double x = points[i].x - points[j].x;
	      double y = points[i].y - points[j].y;
	      if(x == 0 && inf_flag.count(y)) continue;
	      if(x == 0) inf_cnt[y] = inf_cnt.count(y) ? inf_cnt[y]+pcnt+1 : pcnt+1, ans = max(inf_cnt[y], ans), inf_flag[y] = true;
        else {
          double k = y/x;
          y = y - k*x;
          if(x != 0 && cnt_flag.count(k) && cnt_flag[k].count(y)) continue;
          if(cnt.count(k)) cnt[k][y] = cnt[k].count(y) ? cnt[k][y] + pcnt + 1 : pcnt + 1;
          else cnt[k][y] = pcnt;
          ans = max(cnt[k][y], ans);
          cnt_flag[k][y] = true;
        }
	    } 	
	    if(pcnt) ++point_cnt[points[i].x][points[i].y];
      else point_cnt[points[i].x][points[i].y] = 1;
		}
		return (int)((sqrt(1+8*ans) + 1)/2);
	}
};
