class Solution {
public:
	int reverse(int x) {
		char buf[30];
		memset(buf, 0, 30);
		if(x < INT_MIN || x > (1<<31)-1) return 0;
		std::string ans = "";
		sprintf(buf, "%d", x);
		bool flag = false, is_neg = false;
		if(x < 0) is_neg = true;
		for(int i = strlen(buf)-1; i >= 0; --i) {
			if(buf[i] == '0' && flag) {
				ans += buf[i];
			}
			else if(buf[i] != '-'){
				flag = true;
				ans += buf[i];
			}
		}
		long long res = atoll(ans.c_str());
		if(res < INT_MIN || res > INT_MAX) return 0;
		return is_neg ? 0-res : res;
	}
};


// solution 2
class Solution {
public:
	int reverse(int x) {
		long long ans = 0;
		while(x) {
			long long temp = ans*10 + x%10;
			if(temp > INT_MAX || temp < INT_MIN) return 0;
			ans = temp;
			x /= 10;
		}
		return ans;
	}
};
