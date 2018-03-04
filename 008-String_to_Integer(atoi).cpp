class Solution {
public:
    int myAtoi(string str) {
        int base = 0, sign = 1;
		int i = 0;
		while (i < str.size() && str[i] == ' ')
			i++;
		if (i == str.size()) return 0;
		if (str[i] == '-') {
			sign = -1;
			i++;
		}else if (str[i] == '+') {
			sign = 1;
			i++;
		}
		while (str[i] >= '0'&&str[i] <= '9') {
			if (base > (INT_MAX / 10) || base == INT_MAX / 10 && str[i] > '7')
				return sign == 1 ? INT_MAX:INT_MIN;
			base = str[i++] - '0' + base * 10;
		}
		return  base*sign;
    }
};
//此题的关键在于判断str是不是一个合格的数字，而什么是数字题目下面也给出了。按照那个排除一下就好了，很简单
//判断溢出的地方写的很精彩if (base > (INT_MAX / 10) || base == INT_MAX / 10 && str[i] > '7')    return sign == 1 ? INT_MAX:INT_MIN;
