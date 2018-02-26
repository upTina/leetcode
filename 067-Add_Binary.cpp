class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
		int carry = 0;
		int right_a = a.size() - 1;
		int right_b = b.size() - 1;
		int sum = 0, m=0, n=0;
		while (right_a >= 0 || right_b >= 0) {
			m = right_a >= 0 ? a[right_a] - '0' : 0;
			n = right_b >= 0 ? b[right_b] - '0' : 0;
			sum = m + n + carry;
			res = to_string(sum % 2) + res;
			carry = sum>=2?1:0;
			right_a--;
			right_b--;
		}
		return carry == 1 ? "1" + res : res;
    }
};
// 0=‘0’-‘0’，    1=‘1’-‘0’，   2 = ‘2’-‘0’，    9 = ‘9’-‘0’
