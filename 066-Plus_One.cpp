class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
		int sum = 0;
		for (int i = digits.size()-1; i >= 0; --i) {
			sum = digits[i] + carry;
			digits[i] = (sum % 10);
			if (sum >= 10) carry = 1;
			else return digits;
		}
		if (carry == 1) digits.insert(digits.begin(), 1);
		return digits;
    }
};
//这些相加的题目都很简单，唯一需要注意的就是处理最后最高位上的进位问题。
