class Solution {
public:
	bool isMatch(string s, string p) {
		int scur = 0, pcur = 0, sstar = -1, pstar = -1;
		while (scur < s.size()) {
			if (s[scur] == p[pcur] || p[pcur] == '?') {
				scur++;
				pcur++;
			}
			else if (p[pcur] == '*') {
				pstar = pcur++;
				sstar = scur;
			}
			else if (pstar > -1) {
				scur = ++sstar;
				pcur = pstar + 1;
			}
			else return false;
		}

		while (p[pcur] == '*') pcur++;
		return pcur == p.size();
	}
};
//最近做题有个最大感受，就是题再难，也可以大概20行解决。。。
//其次，这个题和做过的正则化匹配很像。受剑指offer的影响，我做这种题情不自禁地要用递归，感觉方便快捷，简单易懂。但是不出意外的超时了
//后来把遇到*的情况改成了一个循环，不断让s=s.substr(1)来和去掉*的p进行比较，还是超时了。
//看了一样大神的，直接遍历即可。四个变量，scur = 0, pcur = 0, sstar = -1, pstar = -1。当遇到有*的情况时，把*的位置记下来，同时用sstar=scur，表示从
//这一位开始，如果我匹配不掉，就可以用*消掉，遇到匹配不掉的情况，就让sstar++，然后scur等于sstar，这样相当于用*消掉了1位，而此时pcur应该回到*后面，
//从这个位置再继续匹配，直到s为空
//s为空的时候，p可以不为空，因为p可以全是***,所以最后要把p中的*全遍历掉，看看是否除了*，p中说明也没有。如果p只包含*，那就说明匹配成功，反之匹配失败。
