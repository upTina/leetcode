class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int flag = 0;
		int count = 0;
		int original_number = nums.size();
		for (int i = 0; i<nums.size();) {
			flag = nums[i];
			for (int j = i + 1; j < nums.size();) {
				if (flag == nums[j]) {
					nums.erase(nums.begin() + j);
					count++;
				}else {
					break;
				}
			}
			i++;
		}
		return original_number - count;
    }
};

//很简单
