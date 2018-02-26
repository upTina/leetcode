class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, cursum = -1000;
		for (int i = 0; i < nums.size(); i++) {
			if (cursum < 0) {
				cursum = nums[i];
			}else {
				cursum += nums[i];
			}
			if (cursum > res)
				res = cursum;
		}
		return res;
    }
};
//按道理这是个经典算法了，操作起来也非常简单，值得仔细思考。上面方法的时间复杂度为O(n)，还可以使用分治法，时间复杂度为O(nlogn)，如下：
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		return findmax(nums, 0, nums.size() - 1);
	}
	int findmax(vector<int>& nums, int left, int right) {
		if (left >= right) return nums[left];
		int mid = (left + right) / 2;
		int lmax = findmax(nums, left, mid - 1);
		int rmax = findmax(nums, mid + 1, right);
		int mmax = nums[mid], t = mmax;
		for (int i = mid - 1; i >= left; i--) {
			t += nums[i];
			mmax = max(t, mmax);
		}
		t = mmax;
		for (int i = mid + 1; i <= right; i++) {
			t += nums[i];
			mmax = max(t, mmax);
		}
		return max(lmax, max(rmax, mmax));
	}
};

//max只能有2个参数

