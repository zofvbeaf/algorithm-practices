class Solution {
public:
  bool isValid(string s) {
    stack<char> temp;
    if(s.empty()) return true;
    if(s.size()%2) return false;
    temp.push(s[0]);
    unordered_map<char, char> brackets;
    brackets[')'] = '(';
    brackets[']'] = '[';
    brackets['}'] = '{';
    for(int i = 1; i < s.size(); ++i) {
      if(brackets.count(s[i])) {
        if(brackets[s[i]] != temp.top()) return false;
        temp.pop();
      }
      else if(!brackets.count(s[i])) temp.push(s[i]);
    }
    return temp.empty();
  }
};
