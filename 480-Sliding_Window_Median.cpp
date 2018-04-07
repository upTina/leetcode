class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		vector<double> res;
		multiset<double> window(nums.begin(), nums.begin() + k);
		auto  mid = next(window.begin(), k / 2);
		for (int i = k;; i++) {
			res.push_back(0.5*(*mid + *prev(mid, 1 - k % 2)));
			if (i == n)
				return res;
			window.insert(nums[i]);
			if (nums[i] < *mid) mid--;
			if (nums[i - k] <= *mid) mid++;
			window.erase(window.lower_bound(nums[i - k]));
		}
	}
};
//首先，这道题目里面，学到了很多函数。next(a,n)，迭代器a+n再返回；prev(a,n),返回迭代器a之前的第n个位置；
//有序容器中lower_bound(num),容器中插入num这个数字的最小位置；upper_bound(num),容器中插入num这个数字的最大位置。注意，当容器中有且只有1个num时
//插入的位置最早就是这个num所在的位置，最晚是这个num之后的1个位置。所以lower_bound和upper_bound结果是不一样的。单独使用lower_bound和upper_bound
//而不是作为set的成员函数使用时，lower_bound和upper_bound会把数组当做有序的来查找num的位置，不管数组是否真的有序。
//erase要擦出的是迭代器，不是具体数字
//迭代器类似指针。vector里面的数字更新后，迭代器会失效。set和map是数结构实现，所以set和map更新后，迭代器仍然指向原来指向的数字，如果数字被删除，
//则指向数字后面的位置。

//其次，学到了计算中位数的一种新方法。如果数组有k个数，mid=k/2，那么中位数就是0.5*(*mid + *prev(mid, 1 - k % 2))

//最后，本题算法的精髓之处。假如当前我们已经寻找到了k个数的中位数位置--迭代器mid，这时再插入或者删除数据，mid所指向的位置便不在是中位数位置，可能会
//往后，也可能会往前。这时应该怎么办的？由于数字最终就只有k个，而且我们的数组multiset永远都是有序的，那么我们只需要令mid和第0个位置之间的距离保持不变
//即可，即只考虑数组的前半部分或者后半部分即可。假如只考虑前半部分，插入或者删除的数据小于等于mid的话，这时mid与第0个位置的距离会发生改变，这时我需要
//调整mid位置。除此情况以外，都不需要考虑。
