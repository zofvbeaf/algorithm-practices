#include <cstdio>
#include <cstring>
using namespace std;
char s[20000], t[2000000];
int next[20000];
void kmp_pre()
{
	int len = strlen(s);
	int i = 0, j = -1;
	next[0] = -1;
	while(i < len)
	{
		if(j == -1 || s[i] == s[j])
		{
			i++, j++;
			next[i] = s[i] == s[j] ? next[j] : j;
		}
		else j = next[j];
	}
	for(int i = 0; i <= len; ++i) 
		printf("%d ", next[i]);
	printf("\n");
}
int kmp()
{
	int i = 0, j = 0;
	int ans = 0, len = strlen(s);
	kmp_pre();
	while(t[j])
	{
		if(i == -1 || s[i] == t[j]) i++, j++;
		else i = next[i];
		if(i == len) ans++;
	}
	return ans;
}
int main(){
	sprintf(s, "ABCDABD");
	kmp_pre();
	return 0;
}
