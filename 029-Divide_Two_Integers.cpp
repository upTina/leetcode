class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN&&divisor == -1) return INT_MAX;
		int res = 0;
		int flag_dividend = 1;
		int flag_divisor = 1;
		long long m = dividend;
		long long n = divisor;
		if (dividend < 0) {
			flag_dividend = -1;
			m = 0 - m;
		}
		if (divisor < 0) {
			flag_divisor = -1;
			n = 0 - n;
		}
		while (m >= n) {
			long long times = 1, div = n;
			while (m > (div << 1)) {
				times <<= 1;
				div <<= 1;
			}
			res += times;
			m -= div;
		}
		return flag_dividend == flag_divisor ? res:0 - res;
	}
};
/*
一开始我直接从被除数里面减去除数，但是很明显，遇到-2147483648除以1的这种情况会超时
那就只好位运算了
想都不用想，运算无非就是加减乘除取余以及位运算，不让加减乘除，那肯定是位运算
位运算的思路也很简单，我之前的思路是一个一个减，但是位运算是这样：
减1个除数可以吗？
可以的话试试减2个除数可以吗？
可以的话试试减去4个可以吗？
8个可以吗？
16个可以吗
。。。
这样程序就快了起来。
*/
