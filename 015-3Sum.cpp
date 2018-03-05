class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0) break;
			if (i != 0 && nums[i] == nums[i-1]) continue;
			int j = i + 1, k = nums.size() - 1;
			while (j < k) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					res.push_back({ nums[i],nums[j],nums[k] });
					while (j < k&&nums[j] == nums[j + 1]) j++ ;
					while (j < k&&nums[k] == nums[k - 1]) k--;
					j++;
					k--;
				}else if (nums[i] + nums[j] + nums[k] > 0)
					k--;
				else j++;
			}
		}
		return res;
    }
};
//这个题目思路很简单直观，按照第一感觉来就可以做，但是有很多优化技巧：
//首先，对数字要进行排序，这样方便跳过重复数字，并且便于后续一些操作；
//其次，因为3个数的和为0，而数字是有序的，所以当进行第一层遍历的时候，如果第一个数字大于0，后面就无需再做了，因为后面的数字肯定都是大于等于零，和一定≥0
//再次，当确定第一个数，比较剩下两个数时，如果二者只和大于target，说明现在需要将和调小一点，那么需要k--；反之，说明需要将和调大一点，需要j++
//当输入数组为空时，nums.size()=0，但是如果使用判断条件i < nums.size()的话，这时nums.size-2 = 4294967294, 因为nums.size()返回的是无符号int，直接溢出了
