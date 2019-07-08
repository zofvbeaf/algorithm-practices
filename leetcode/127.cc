class Solution {
public:
  void search(string beginWord, string endWord, vector<string>& wordList, vector<int>& f, int distance) {
    if(distance >= ans) return;
    if(beginWord == endWord) {
      ans = min(ans, distance);
      return;
    } 
    for(int i = 0; i < wordList.size(); ++i) {
      if(f[i] != 0) return;
      int cnt = 0;
      for(int j = 0; j < wordList[i].size(); ++j) 
        cnt += (wordList[i][j] != beginWord[i]);
      if(cnt == 1) f[i] = distance + 1;
    }
    for(int i = 0; i < wordList.size(); ++i) {
      if(f[i] == distance + 1) 
        search(wordList[i], endWord, wordList, f, distance+1);
    }
    for(int i = 0; i < wordList.size(); ++i) {
      if(f[i] == distance + 1) f[i] = 0;
    }
  }

	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(beginWord.size() != endWord.size()) return 0;
    bool can_find = false;
    ans = INT_MAX;
    vector<int> f(wordList.size(), 0);
    for(int k = 0; k < wordList.size(); ++k) {
      if(wordList[k].size() != beginWord.size()) {
        f[k] = -1;
        continue;
      }
      if(wordList[k] == endWord) can_find = true;
      int cnt = 0;
      for(int i = 0; i < wordList[k].size(); ++i) 
        cnt += (wordList[k][i] != beginWord[i]);
      if(cnt == 1) f[k] = 1; 
    }
    for(int i = 0; i < wordList.size(); ++i) {
      if(f[i] == 1) search(wordList[i], endWord, wordList, f, 1);
    }
    return ans;
	}
	int ans;
};
