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


