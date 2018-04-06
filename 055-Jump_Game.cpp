class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		vector<int> dp(n);
		for (int i = 1; i < n; i++) {
			dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
			if (dp[i] < 0)
				return false;
		}
		return dp[n - 1] < 0 ? false : true;;
	}
};
//动态规划，用一个数组表示走到当前这一步，我最多能多出来多少步。如果是负数，说明走不到这一步，如果是其他数，这个数可以为未来跳格子提供帮助。
