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

//再往后，
