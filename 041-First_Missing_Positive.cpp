class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) return 1;
		for (int i = 0; i < nums.size(); ) {
			if(nums[i]>=0&&nums[i]<=nums.size()&&nums[nums[i]-1]!=nums[i]){
				swap(nums[i], nums[nums[i] - 1]);
			}
			else {
				i++;
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return nums.size()+1;
	}
};
/*
这道题其实很简单，但是要求很高，时间复杂度为n，空间复杂度为1.
做题做到现在，有几点体会：
1.时间复杂度比空间复杂度更重要，所以能省时就省时
2.省时的话，除了算法巧妙，最大的方法就是用一个辅助内存把中间数据存下来，便于后续使用，而这一般要用到哈希表，而哈希表需要n的辅助内存
3.在本题这种常数空间复杂度的怎么办呢？，那就是利用数组本身，用数组本身来存我们的数据，在数组上修修改改。
4.本题这个找第一个确实的正数是这么做，而有一个找整数中的重复数字也是这么做。
*/
