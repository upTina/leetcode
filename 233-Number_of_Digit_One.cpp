//自己的是一种非常简单直观的方法：如果我的函数是f(n),一个数是4321，那么这个我可以计算0-4000里面有多少个1，然后加上f(321)，这样递归来做
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)
            return 0;
        string num = to_string(n);
		return howmany(num);
    }
    int howmany(string num) {
		int bit_num = num.size();
		if (bit_num == 0)
			return 0;
		else if (bit_num == 1) {
			if (num[0] >= '1')
				return 1;
			else
				return 0;
		}
		else {
			if (num[0] == '0')
				return howmany(num.substr(1));
			else if(num[0] == '1') {
				return (bit_num-1)*pow(10, bit_num - 2) + stoi(num.substr(1)) + 1 + howmany(num.substr(1));
			}
			else {
				return (num[0] - '0')*(bit_num - 1)*pow(10, bit_num - 2) + pow(10, bit_num - 1)  + howmany(num.substr(1));
			}
		}
	}
};
//下面是一种目前我还没看懂的做法。。。
class Solution {
public:
	int countDigitOne(int n) {
		int res = 0, a = 1, b = 1;
		while (n > 0) {
			res += (n + 8) / 10 * a + (n % 10 == 1) * b;
			b += n % 10 * a;
			a *= 10;
			n /= 10;
		}
		return res;
	}
};
