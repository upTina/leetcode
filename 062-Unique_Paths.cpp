class Solution {
public:
	int uniquePaths(int m, int n) {
		if (n <= 0 || n <= 0) return 0;
		int total_num = m + n - 2;
		int num = min(m - 1, n - 1);
		long long dividend = 1;
		long long divisor = 1;
		for (int i = 0; i < num; i++) {
			dividend *= total_num - i;
			divisor *= i + 1;
		}
		return dividend / divisor;
	}
};
//上面的解法是标准的排列组合解法，只不过是把组合数化简以后，因为求阶乘是一个很大的数，很容易溢出。而这样还是溢出了，所以只好用longlong变量
//下面的解法是动态规划，这个方法好。加加减减就可以
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1]; 
            }
        }
        return dp[n - 1];
    }
};
