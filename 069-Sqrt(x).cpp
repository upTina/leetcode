class Solution {
public:
    int mySqrt(int n) {
		double x = n;
		while (x*x - n > 0.1) {
			x = x - (x*x - n) / (2 * x);
		}
		return int(x);
    }
};
//牛顿迭代法
