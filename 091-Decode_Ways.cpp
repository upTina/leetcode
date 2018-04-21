class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0 || s[0] == '0') return 0;
		int n = s.size();
		vector<int> dp(n, 0);
		dp[0] = 1;
		if (n >= 2 && s.substr(0, 2) >= "10"&&s.substr(0, 2) <= "26")
			dp[1] = 1;
		if (n >= 2 && s[1] != '0')
			dp[1]++;
		for (int i = 2; i < n; i++) {
			if (s[i] != '0') {
				dp[i] += dp[i - 1];
			}
			if (s.substr(i - 1, 2) >= "10"&&s.substr(i - 1, 2) <= "26")
				dp[i] += dp[i - 2];
			if (dp[i] == 0) return 0;
		}
		return dp[n - 1];
	}
};
//动态规划，中间有个地方让我麻烦了好久。string.substr(pos,length)这个成员函数substr的第一个参数是子串的起始位置，第二个参数是要截取的子串的长度，
//没有的话默认为直到字符串结尾。我一开始以为substr是表示子串的首位位置，结果因为这个地方麻烦了一会儿
