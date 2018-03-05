class Solution {
public:
    string intToRoman(int num) {
        string list[4][10] = {
			"","I","II","III","IV","V","VI","VII","VIII","IX",
			"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC",
			"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM",
			"","M","MM","MMM"
		};
		string res = "";
		res += list[3][num / 1000 % 10];
		res += list[2][num / 100 % 10];
		res += list[1][num / 10 % 10];
		res += list[0][num % 10];
		return res;
    }
};
//百度了一下10以上的罗马数字是什么，然后就看到百度百科里这段代码，非常屌
