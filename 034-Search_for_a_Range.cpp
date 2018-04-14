class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int first = findfirst(nums, target);
		int last = findlast(nums, target);
		return vector<int> { first,last };
	}
	int findfirst(vector<int>&nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				if (mid == 0||nums[mid-1]!=target) return mid;
				else right = mid - 1;
			}
			else if (nums[mid] > target) right = mid - 1;
			else left = mid + 1;
		}
		return -1;
	}
	int findlast(vector<int>&nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				if (mid == nums.size() - 1 || nums[mid + 1] != target) return mid;
				else left = mid + 1;
			}
			else if (nums[mid] > target) right = mid - 1;
			else left = mid + 1;
		}
		return -1;
	}
};
//剑指offer上的原题。本来可以先找到这个数，然后向前向后搜索范围宽度。但是这个并不是严格的logn，因为如果所有的数都相等，这复杂度为n
//所以应该写两个二分超找，分别寻找范围的第一个数和最后一个数，他们的范围就是我们想要找到的范围。
