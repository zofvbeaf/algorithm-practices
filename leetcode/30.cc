class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
	  vector<int> ans;
    if(words.empty()) return ans;
    unordered_map<string, int> words_map;
    for(int i = 0; i < words.size(); ++i) 
      words_map[words[i]] = words_map.count(words[i]) ? words_map[words[i]] + 1 : 1;
    int n = words.size(), m = words[0].size(), x = s.size();
    unordered_map<int, unordered_map<string, int>> temp;
    for(int i = 0; i <= x-m; ++i) {
      if(i >= n*m && temp[i%m].count(s.substr(i-n*m, m))) {
        --temp[i%m][s.substr(i-n*m, m)];
        if(!temp[i%m][s.substr(i-n*m, m)]) temp[i%m].erase(s.substr(i-n*m, m));
      }
      if(words_map.count(s.substr(i, m))) 
        temp[i%m][s.substr(i, m)] = temp[i%m].count(s.substr(i, m)) ? temp[i%m][s.substr(i, m)] +1 : 1;
      if(temp[i%m].size() == words_map.size()) {
        bool flag = true;
        for(auto it : words_map) 
          if(temp[i%m][it.first] != it.second) {
            flag = false;
            break;
          }
        if(flag) ans.push_back(i-(n-1)*m);
      }
    }
    return ans;
	}
};
