class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (target == nums[mid]) return mid;
			else if (target > nums[mid]) {
				left = mid + 1;
			}else
				right = mid - 1;
		}
		return left;
    }
};
//标准的折半查找.1,while(left<=right);2,return left
