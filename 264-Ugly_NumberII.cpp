//自己的做法，以为可能有重复数字，所以我使用set来存储数据。这个在牛客网上剑指offer提交板块是无法通过的，可能是clang++编译器的问题
class Solution {
public:
    int nthUglyNumber(int n) {
        int index = n;
        if (index <= 0) return 0;
		int a, b, c;
		int curr_num = 1;
		set<int> ugly{1};
		auto i = ugly.begin();
		auto j = ugly.begin();
		auto k = ugly.begin();
		while (ugly.size() < index) {
			a = *i * 2;
			b = *j * 3;
			c = *k * 5;
			if (a <= b&&a <= c) {
				ugly.insert(a);
				++i;
			}else if (b <= a&&b <= c) {
				ugly.insert(b);
				++j;
			}else {
				ugly.insert(c);
				++k;
			}
		}
        return *(--ugly.end());
    }
};
//下面是大神标准做法
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 7)return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i)
        {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)t2++;
            if (res[i] == res[t3] * 3)t3++;
            if (res[i] == res[t5] * 5)t5++;
        }
        return res[index - 1];
    }
};
//其实不管重复不重复，我们需要比较最后插入的时候的4个数即可，res[i]，res[t2] * 2，res[t3] * 3，res[t5] * 5。
//我一开始在想乘积也许会和之前的数重复，而重复的数字可能是当前乘积可res之前的数字重复，这样每次都要判断一下是否重复，计算起来很麻烦，所以直接没有沿着这个思路走，直接用set来做了。
//但是思考一下，重复的数字只可能是上面4个。因为我们每次放入res中中的数都是当前要放进去的最小的丑数。假如现在的2、3、5与当前各自指向的res乘积比我要
//放入res中的数字小，那么这个丑数肯定已经被加入到res当中了，而对应的指针t2,t3,t5已经进行++操作了。所以，现在所有的res[t2] * 2，res[t3] * 3，res[t5] * 5
//要么比即将加入res中的数大，要么和即将加入res中的数相等。所以我们只需要在相等的那种情况下，让t++即可
















