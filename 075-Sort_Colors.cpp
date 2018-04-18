class Solution {
public:
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return;
		int red_pos = 0;
		int blue_pos = n - 1;
		int i = 0;
		while (i <= blue_pos) {
			if (nums[i] == 0) {
				if (i == red_pos) {
					red_pos++;
					i++;
				}
				else {
					swap(nums[i], nums[red_pos++]);
				}
			}
			else if (nums[i] == 2) {
				swap(nums[i], nums[blue_pos--]);
			}
			else
				i++;
		}
	}
};
//很简单
