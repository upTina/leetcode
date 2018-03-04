class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1001][1001] = {0};
		int num = s.size();
		int max = 1, max_i = 0;
		for (int dist = 0; dist < num; dist++) {
			for (int i = 0; i + dist < num; i++) {
				if (dist == 0) {
					dp[i][i] = 1;
				}else if (dist == 1) {
					if (s[i] == s[i+1]) dp[i][i + 1] = 1;
					else dp[i][i + 1] = 0;
				}else {
					if (s[i] == s[i + dist] && dp[i + 1][i + dist - 1]) dp[i][i + dist] = 1;
					else dp[i][i + dist] = 0;
				}
				if (dp[i][i + dist] == 1&&dist+1>max) {
					max = dist + 1;
					max_i = i;
				}
			}
		}
		return s.substr(max_i, max);
    }
};
//标准动态规划问题，原问题可以拆分为较小规模的子问题，而子问题又频频出现，所以用一个表把子问题结果直接存起来，然后查表做题
