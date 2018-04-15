class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		vector<int> dp(n, 0);
		int num = 0;
		int mx = 0;
		for(int i=0;i<n;i++){
			dp[i] = mx;
			mx = max(height[i], mx);
		}
		mx = 0;
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = min(dp[i], mx);
			mx = max(mx, height[i]);
			if (dp[i] > height[i]) num += dp[i] - height[i];
		}
		return num;
	}
};
/*
基本思路，计算每个方格上方能存多少水，然后把所有的水加起来。
方格上方能存税的高度，就是方格左边的最大高度和方格右边最大高度围起来能存水的高度。也就是两个最大值中间较小的那个值。
同时，这个高度还要大于方格本身的高度，这样才能蓄水。所以方格存水是dp[i]-height[i]。
这个题的解法很直接，但是却没有想出来。只想出来一个超时的算法，难道还是我缺乏锻炼？
最近做题有些急于求成，贪多务得。只想着赶紧做，多做几道，但是却并没有真正的思考。这是一种非常不好的现象。
*/
