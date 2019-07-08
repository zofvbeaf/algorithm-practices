class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
	  vector<string> ans;
		int x = 0, len = 0;
		for(int i = 0; i < words.size(); ++i) {
		  if(words[i].size()+len+(i-x) <= maxWidth) len += words[i].size();
      else {
        string s;
        int spaces = maxWidth-len;
        for(int j = x; j < i; ++j) {
          s += words[j];
          if(j < i-1) {
            s += string(spaces/(i-j-1)+((spaces%(i-j-1) > 0)), ' ');
            spaces -= spaces/(i-j-1)+((spaces%(i-j-1)) > 0);
          }
        }
        s += string(maxWidth-s.size(), ' '); 
        ans.push_back(s);
        len = words[i].size(), x = i;
      }
		}
    string s;
    for(int j = x; j < words.size(); ++j) {
      s += words[j];
      if(j < words.size() - 1) s += ' ';
    }
    if(!s.empty()) ans.push_back(s);
    ans.back() += string(maxWidth-ans.back().size(), ' ');  
    std::cout << ans.back().size() << std::endl;
    return ans;
	}
};


