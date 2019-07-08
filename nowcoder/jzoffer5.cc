class Solution {
public:
	void replaceSpace(char *str,int length) {
		if(!str) return;
	  int old_len = 0;
	  int space_num = 0;
	  while(str[old_len] != '\0') {
	    if(str[old_len++] == ' ') 
	      ++space_num;
	  }
	  int new_len = space_num*2 + old_len;
	  if(new_len > length) 
	    return;
	  
	  for(int i = old_len, j = new_len; i >= 0; --i, --j) {
	    if(str[i] == ' ') {
	      str[j] = '0';
	      str[j-1] = '2';
	      str[j-2] = '%';
	      j -= 2;
	    }
      else 
        str[j] = str[i];
	  }
	}
};
