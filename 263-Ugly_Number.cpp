class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0)return false;
		while (num % 2 == 0) num /= 2;
		while (num % 3 == 0) num /= 3;
		while (num % 5 == 0) num /= 5;
		return num == 1;
	}
};
//假如一个数是丑数的话，那他首先得是正数，其次，他的只能包含2、3、5这几个因子，所以他把2、3、5都除完以后，应该只剩一个1
