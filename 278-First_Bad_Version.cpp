bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1;
		int right = n;
		int mid;
		bool res;
		while (left <= right) {
			mid = left + (right - left) / 2;
			res = isBadVersion(mid);
			if (res == false) left = mid + 1;
			else {
				if (mid == 1) return 1;
				if (isBadVersion(mid - 1) == false) return mid;
				else right = mid - 1;
			}
		}
	}
};
/*
二分查找的形式多种多样，总而言之，假如你需要在一个有序或者部分有序的数组、矩阵、区间等等一定范围内找东西，那你基本上都要用二分查找法
一般的二分查找，找到了就是找到了，没找到就是没找到；而有的二分法，则一定会找到，比如猜数字，比如本题
我印象最深的查找，是查找数字的插入位置。假如有序数组里一个要插入的数字本来就存在，那么那个数字的位置就是插入位置。但是加入不存在，就需要最后锁定到一个
区间。我只记得最后是返回left的位置就可以了。具体是什么，遇到题目再说吧。
*/
