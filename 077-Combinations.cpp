class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> res_temp;
		backtrack(res, res_temp, -1, n, k);
		return res;
	}
	void backtrack(vector<vector<int>>&res, vector<int>res_temp, int cur, int n, int k) {
		if (res_temp.size() == k){
			res.push_back(res_temp);
			return;
		}
		for (int i = 1; i <= n; i++) {
			if (i > cur) {
				vector<int>temp(res_temp);
				temp.push_back(i);
				backtrack(res, temp, i, n, k);
			}
		}
	}
};
/*
回溯这种方法，越做越简单。只要处理好三个问题：
1.递归体里面，我要做什么事情
2.我要调用递归体的话，要把什么东西送到下一次的递归体里
3.什么时候递归停止
*/
