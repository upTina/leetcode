class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int min=INT_MAX;
		for (int i = 0;i<nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == target) return target;
				else if (nums[i] + nums[j] + nums[k] > target) {
					if (fabs(nums[i] + nums[j] + nums[k] - target) < fabs(min - target))
						min = nums[i] + nums[j] + nums[k];
					while (j < k&&nums[k] == nums[k - 1]) k--;
					k--;
				}else {
					if (fabs(nums[i] + nums[j] + nums[k] - target) < fabs(min - target))
						min = nums[i] + nums[j] + nums[k];
					while (j < k&&nums[j] == nums[j + 1]) j++;
					j++;
				}
			}
		}
		return min;
    }
};
//跟那个求三个数的和一模一样
