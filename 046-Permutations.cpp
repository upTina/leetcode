class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0)
			return vector<vector<int>>{};
		vector<vector<int>> res;
		res.push_back(nums);
		vector<int>temp_nums;
		vector<vector<int>> temp_res;
		for (int i = 0; i < nums.size()-1; i++) {
			for (int j = 0; j < res.size(); j++) {
				for (int k = i; k < nums.size(); k++) {
					temp_nums = res[j];
					swap(temp_nums[i], temp_nums[k]);
					temp_res.push_back(temp_nums);
				}
			}
			res = temp_res;
			temp_res.clear();
		}
		return res;
	}
};
//剑指offer上看到过此题，不得不感叹剑指offer的针对性和覆盖面
//有的题目要求是按顺序排列的，此题没有。
//先将nums存到一个res中
//从最高位开始交换，用i表示要交换的位置，这样确保顺序一直是按照给出的顺序排列的。
//交换哪里的数字呢？交换res中的数字，用j表示当前正在交换res中的第j个数字。从res中取出数字，然后那第i位依次与i之后的位置(包括i本身的位置)进行交换，
//每交换得到新的数字，就将新数字存下来，放到temp_res中。把res中所有数字交换完之后，再将temp_res的值赋给res，得到新的res
//然后++i，继续交换i与i的下一位，知道i移动到最后，不需要交换。交换结束。
