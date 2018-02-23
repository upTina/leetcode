class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++) {
			if (hash.count(target - nums[i])) {
				return{hash[target-nums[i]],i};
			}
			hash[nums[i]] = i;
		}
	}
};

###1.c++11可以使用大括号{}来初始化vector，所以最后可以直接返回｛hash[target-nums[i]], i｝
###2.本题可以使用a暴力搜索b2次遍历c3次遍历来进行解答，其中方法b和c都是使用哈希表（unordered_map），哈希表的键值表示原数据的数值，值表示原数据的索引
