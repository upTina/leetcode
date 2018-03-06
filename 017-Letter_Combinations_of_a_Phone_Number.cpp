class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string letter[10] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		vector<string> res,temp;
		if (digits.size() == 0) return res;
		string a = "sdfasf";
		int i = 0;
		string str;
		while (i < letter[(digits[0]-'0')%10].size()) {
			str = letter[(digits[0] - '0') % 10][i++];
			temp.push_back(str);
		}
		res = temp;
		temp.clear();
		for (int i = 1; i < digits.size(); i++) {
			for (int j = 0; j < res.size(); j++) {
				for (int k = 0; k < letter[(digits[i] - '0') % 10].size(); k++) {
					str = res[j] + letter[(digits[i] - '0') % 10][k];
					temp.push_back(str);
				}
			}
			res = temp;
			temp.clear();
		}
		return res;
    }
};
//感觉还挺简单
