class MedianFinder {
public:
	void addNum(int num) {
		max_heap.insert(num);
		min_heap.insert(-*max_heap.begin());
		max_heap.erase(max_heap.begin());
		if (max_heap.size() < min_heap.size()) {
			max_heap.insert(-*min_heap.begin());
			min_heap.erase(min_heap.begin());
		}
	}

	double findMedian() {
		return (max_heap.size() > min_heap.size()) ? *max_heap.begin() : 0.5*(*max_heap.begin() - *min_heap.begin());
	}
private:
	multiset<int> max_heap, min_heap;
};
//用最大堆存前半部分，最小堆存后半部分。那么中位数肯定就可以用最大堆的begin和最小堆的begin计算出来。这个解法有2个技巧，非常非常巧妙：
//1、最大堆和最小堆定义的时候为了方便，都使用最大堆来定义，但是在把数据插入最小堆的时候，在前面乘以一个-1，那么最小堆里的存放顺序其实
//就是最大堆的逻辑（直接定义最小堆不是更省事吗。。。。。。）
//2、存放数据的时候，永远都是先把数据插入最大堆，然后再把最大堆里的最大数插入最小堆。这些操作都做完了以后，在调整各个堆的数量。（插入
//的时候直接根据数量插入不也挺简单吗。。。）
