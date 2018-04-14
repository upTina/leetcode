class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] == target) return mid;
			else if (nums[mid] >= nums[left]) {
				if (target >= nums[left] && target < nums[mid]) right = mid - 1;
				else left = mid + 1;
			}
			else if (nums[mid] < nums[right]) {
				if (target > nums[mid] && target <= nums[right]) left = mid + 1;
				else right = mid - 1;
			}
		}
		return -1;
	}
};
//假如数组经过了旋转，我们使用二分查找，会出现一半的数字是无序的情况。但是另一半还是有序的，所以我们只要判断一下数字在不再另一半中，就可以知道我们
//接下来该对哪段数字进行取舍了
//如果数组没有旋转呢？那就更好判断了，应为我们判断的时候是挑选一段有序的来进行判断，数组如果没有旋转，那么每一段都是有序的，我们的判断方法肯定也对
