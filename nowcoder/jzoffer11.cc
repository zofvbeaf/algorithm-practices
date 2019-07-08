class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
	  int left = 0, right = rotateArray.size() - 1, mid = 0; 
	  while(rotateArray[left] >= rotateArray[right]) {
	    if(right - left == 1) 
	      return rotateArray[right];
	    if(rotateArray[left] == rotateArray[mid]
	        && rotateArray[right] == rotateArray[mid]) {
	      int res = rotateArray[left];
	      while(left <= right) {
	        res = res < rotateArray[left] ? res : rotateArray[left];
	        ++left;
	      }
	      return res;
	    }
	    int mid = (left+right) >> 1;
	    if(rotateArray[left] <= rotateArray[mid]) 
	      left = mid;
      else if(rotateArray[mid] <= rotateArray[right])
        right = mid;
	  }
	  return rotateArray[mid];
	}
};
