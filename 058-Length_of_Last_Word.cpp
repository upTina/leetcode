class Solution {
public:
    int lengthOfLastWord(string s) {
        for (int i = s.size()-1; i >= 0;i--) {
			if (s[i] == ' ') { 
				s.erase(s.begin() + i);
			}
			else break;
		}
		int count = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == ' ') return count;
			else count++;
		}
		return count;
    }
};
//简单
