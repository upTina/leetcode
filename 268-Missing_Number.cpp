class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
			res ^= i^nums[i];
		res ^= nums.size();
		return res;
	}
};
//本来有0-n，n+1ge个数，但是现在缺了1个数，给我们n个数，问我们缺了哪个。时间复杂度为n，空间复杂度为常数。
//第一个办法，0-n这n+1个数的和可以求出来，给我们的n个数的和也可以求出来，然后相减，这个差就是缺的那个数
//第二个办法，用异或。相同的数的异或值为0，那么把n个数和n+1个数异或，最后结果，就是那个缺的数。
//第三个办法，我的办法。把第0个数放在第0个位置，那么最后放n这个数的位置，就是缺少数的位置。
