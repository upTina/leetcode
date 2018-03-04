class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
		int num = numRows * 2 - 2;
		string res = "";
		int a = 0, b = 0;
		for (int i = 0; i < numRows; i++) {
			if (i == 0) {
				for (a = 0; a < s.size();) {
					res += s[a];
					a += num;
				}
			}else if (i == numRows - 1) {
				for (a = numRows - 1; a < s.size();) {
					res += s[a];
					a += num;
				}
			}else {
				for (a = i, b = num - i; a < s.size() || b < s.size();) {
					if(a<s.size())
						res += s[a];
					if(b<s.size())
						res += s[b];
					a += num;
					b += num;
				}
			}
		}
		return res;
    }
};
//基本的找规律的题目：
//第1行的坐标以0为起始位置，隔2numRows-1取一个字符；
//最后一行以numRows为起始位置，隔2numRows-1取一个字符；
//中间的第i行，以i和2numRows-1-i为起始位置，隔2numRows-1取一个字符。
