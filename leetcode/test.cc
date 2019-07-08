#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void search(string beginWord, string endWord, vector<string>& wordList, vector<int>& f, int distance) {
		if(distance >= ans) return;
		if(beginWord == endWord) {
			ans = min(ans, distance);
			return;
		} 
		for(int i = 0; i < wordList.size(); ++i) {
			if(f[i] != 0) continue;
			int cnt = 0;
			for(int j = 0; j < wordList[i].size(); ++j) 
				cnt += (wordList[i][j] != beginWord[j]);
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
		return ans == INT_MAX ? 0 : ans+1;
	}
	int ans;
};

int main() {
	Solution sol;
	string s, t, x;
	cin >> s >> t;
	vector<string> v;
	while(cin >> x) v.push_back(x);
	cout << "ans: " << endl << sol.ladderLength(s, t, v) << endl;
	//int x;
	//cin >> x;
	//auto ans = sol.lexicalOrder(x);
	//for(auto i : ans) cout << i << endl;

	//string s, p;
	//std::cin >> s >> p;
	//std::cout << sol.isMatch(s, p) << std::endl;
	return 0;
}

//class Solution {
//public:
	//int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//unordered_set<string> dict(wordList.begin(), wordList.end());
		//queue<string> todo;
		//todo.push(beginWord);
		//int ladder = 1;
		//while (!todo.empty()) {
			//int n = todo.size();
			//for (int i = 0; i < n; i++) {
				//string word = todo.front();
				//todo.pop();
				//if (word == endWord) {
					//return ladder;
				//}
				//addWords(todo, dict, word);
			//}
			//ladder++;
		//}
		//return 0;
	//}
//private:
	//void addWords(queue<string>& todo, unordered_set<string>& dict, string word) {
		//for (int i = 0; i < word.size(); i++) {
			//char t = word[i];
			//for (int j = 0; j < 26; j++) {
				//word[i] = 'a' + j;
				//if (dict.find(word) != dict.end()) {
					//todo.push(word);
					//dict.erase(word);
				//}
			//}
			//word[i] = t;
		//}
	//}
/*};*/
