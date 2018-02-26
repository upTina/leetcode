class Solution {
public:
   int climbStairs(int n) {
		if (n <= 1) return 1;
		vector<int> dp(n);
		dp[0] = 1, dp[1] = 2;
		for(int i=2;i<n;i++){
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n-1];
	}
};
//该问题是斐波那契数列
//首先想到是递归，但是发现超时了，因为递归把问题分成很多子问题，而很多这些子问题都是重复的，所以可以用动态规划的方法，记录这些子问题的结果。
//我们使用数组记录了从第0个台阶到每一个台阶的方法数，这样大可不必，因为我们只需要知道从第0个到最后一个的方法数就行了，所以用a、b两个变量循环求解就可以了
class Solution {
public:
   int climbStairs(int n) {
		int a = 1, b = 1;
		if (n <= 1) return 1;
		while (n>1) {
			b = a + b;
			a = b - a;
			n--;
		}
		return b;
	}
};
