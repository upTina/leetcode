int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
		int high = n;
		int mid;
        int flag = 0;
		while (low <= high) {
			mid = low+( high - low) / 2;
            flag = guess(mid);
            if (flag == 1) {
				low = mid + 1;
			}
			else if(flag==-1) {
				high = mid - 1;
			}
			 else return mid;
			
		}
    }
};
//其他代码都不变，mid = (low+high)/ 2就会超时，而mid = low+( high - low) / 2就会ac。
//以后求中点，认准mid=low+(high-low)/2
//一个更合理的解释是：计算low+high的时候可能会存在溢出的情况
