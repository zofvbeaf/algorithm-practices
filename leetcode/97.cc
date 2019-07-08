class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), m = s3.size();
    if(m != n1 + n2) return false;
    bool f[n1+1][n2+1];
    for(int i = 0; i <= n1; ++i)
      for(int j = 0; j <= n2; ++j) {
        if(i == 0 && j == 0) f[i][j] = true;
        else if(i == 0) f[i][j] = (f[i][j-1] && s3[i+j-1] == s2[j-1]);
        else if(j == 0) f[i][j] = (f[i-1][j] && s3[i+j-1] == s1[i-1]);
        else f[i][j] = ((f[i][j-1] && s3[i+j-1] == s2[j-1]) || (f[i-1][j] && s3[i+j-1] == s1[i-1]));
      }
    return f[n1][n2];
	}
};
