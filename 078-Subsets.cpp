class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int>res_temp;
		int n = nums.size();
		backtrack(res, res_temp, -1, nums);
		res.push_back(vector<int>{});
		return res;
	}
	void backtrack(vector<vector<int>>&res, vector<int>res_temp, int cur, vector<int>&nums) {
		for (int i = 0; i < nums.size(); i++) {
			if (i > cur) {
				vector<int> temp(res_temp);
				temp.push_back(nums[i]);
				res.push_back(temp);
				backtrack(res, temp, i, nums);
			}
		}
	}
};
//回溯法就是用递归的方法穷举所有的结果，唯一的不同在于，回溯法穷举的时候，知道什么时候进入递归函数，什么时候不需要进入递归函数
