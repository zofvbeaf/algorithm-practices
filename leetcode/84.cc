class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    if(heights.empty()) return 0;
    vector<int> left(heights.size(), 0);
    vector<int> right(heights.size(), 0);
    int ans = 0;
    left[0] = -1;
    right[heights.size()-1] = heights.size();
    for(int i = 1; i < heights.size(); ++i)  {
      int p = i-1;
      while(p >= 0 && heights[p] >= heights[i]) p = left[p];
      left[i] = p;
    }
    for(int i = heights.size()-2; i >= 0; --i)  {
      int p = i+1;
      while(p < heights.size() && heights[p] >= heights[i]) p = right[p];
      right[i] = p;
    }
    for(int i = 0; i < heights.size(); ++i) 
      ans =  max(ans, (right[i]-left[i]-1)*heights[i]);

    return ans;
  }
};
