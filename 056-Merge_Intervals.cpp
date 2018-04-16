class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		map<int, vector<int>> m;
		for (int i = 0; i < intervals.size(); i++) {
			m[intervals[i].start].push_back(-1);
			m[intervals[i].end].push_back(1);
		}
		Interval interv;
		int sum = 0;
		vector<Interval> res;
		int s;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if (sum == 0) {
				s = iter->first;
			}
			for (int i = 0; i < iter->second.size(); i++)
				sum += iter->second[i];
			if (sum == 0)
				res.push_back(Interval(s,iter->first));
		}
		return res;
	}
};
/*
合并区间。首先想到了把所有的数排序，并且排序的时候标记每个数是左端点还是右端点。后来一想，map就能把键值排序，而键对应的值就用-1和1来表示左右端点就可以了。
后来又一想，一个键可能对应多个端点，于是乎，键应该对应一个vector，来存所有的1和1.
合并的时候，从map的第一个元素开始，用一个sum做标记。遍历之前如果sum为0，说明这是左端点，存到变量s里面，然后把当前节点对应的值全部加起来。
如果加起来以后sum为0，这说明当前值key可以作为1个右端点。于是乎把Interval(s,key)存到结果里。然后继续
p.s.这个题上来把我难了一下子，但是我并没有去着急看答案，而是独立思考了一波，于是解决了出来。感觉主要是一来见得题慢慢变多了，所以也容易有思路了。二来对c++
也越来越熟悉了，有想法能很快实现了。
*/
