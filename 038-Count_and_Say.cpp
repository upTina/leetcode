class Solution {
public:
    string countAndSay(int n) {
        string seq = "1";
		string new_seq = "";
		int count = 0;
		char number;
		for (int i = 0; i < n-1; i++) {
			number = seq[0];
			count = 0;
			for (int j = 0; j < seq.size(); j++) {
				if (seq[j] == number) count++;
				else {
					new_seq += to_string(count) + number;
					count = 1;
					number = seq[j];
				}
			}
			new_seq = new_seq + to_string(count) + number;
			seq = new_seq;
			new_seq = "";
		}
		return seq;
    }
};
//很简单，顺着最常见的思路就坐下来了。c++自带的这些东西真方便
