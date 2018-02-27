class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int total = nums1.size() + nums2.size();
		if (total % 2 == 1) {
			return findKth(nums1, 0, nums2, 0, total / 2 + 1);
		}else {
			return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
		}
	}
	double findKth(vector<int>& nums1, int i, vector<int>&nums2, int j, int k) {
		if (nums1.size()-i > nums2.size()-j) return findKth(nums2, j, nums1, i, k);
		if (nums1.size() == i) return nums2[j + k - 1];
		if (k == 1) return min(nums1[i], nums2[j]);
		int right1 = min(i + k / 2, int(nums1.size()));
		int right2 = j + k - right1 + i;
		if (nums1[right1-1] > nums2[right2-1]) {
			return findKth(nums1, i, nums2, right2, k-right2+j);
		}else if (nums1[right1-1] < nums2[right2-1]) {
			return findKth(nums1, right1, nums2, j,k-right1+i);
		}else
			return nums1[right1-1];
	}
};
//不愧是hard难度的，确实新颖。用二分查找法，把要找的数字分成一半，各从各个数组里寻找，然后继续。
//这个问题的关键在于边界问题，其次就是分成2个函数递归的写，更加简单明了。
//这个问题值得多思考
