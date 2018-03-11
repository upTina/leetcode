class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
		int high = nums.size() - 1;
		int mid = (low + high) / 2;
		int count;
		while (low <= high) {
            count = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (nums[i] >= low && nums[i] <= mid)
					count++;
			}
			if (low == high) {
				if (count > 1)
					return low;
			}
			if (count > mid - low+1) {
				high = mid;
				mid = (low + high) / 2;
			}
			else {
				low = mid + 1;
				mid = (low + high) / 2;
			}
		}
    }
};
//此题目有要求，不能改变原数组，使用的空间必须是常数复杂度，所以这说明不可以排序、也不可以用哈希来找重复的。
//那么可以用折半查找法，找到重复的那个数。
/*****************************************************************************************
//我发现折半查找的终止值和边界条件都不是很相同，这个需要每次都验证一下。或者可以这么说，折半只是一种思想，但是每次折半的时候具体情况很不同，
//比如有的时候查找的时候会和mid所在的值比较一下，有的时候不会和mid所在的值比较，所以每次的终止条件都不太相似，返回的值也都不太相似。
//如果查找的过程中已经和mid的值比较过了，那么最后就不需要判断mid本身；如果查找的过程中不断的在和mid比较，那么返回的时候也许只返回low即可
*****************************************************************************************/
//有n个数，数字的值位于1~n-1之间，如果只有一个重复的数字，这个数字一定存在。这种题目有个专门的解法叫做映射找环法，非常牛逼，下面是代码。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
		while (1) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast)
				break;
		}
		int finder = 0;
		while (1) {
			slow = nums[slow];
			finder = nums[finder];
			if (slow == finder)
				return finder;
		}
    }
};
