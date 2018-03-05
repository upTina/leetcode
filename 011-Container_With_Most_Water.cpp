class Solution {
public:
    int maxArea(vector<int>& height) {
    int res = 0;
		int i = 0, j = height.size()-1;
		while (i < j) {
			res = max(res, min(height[i], height[j])*(j - i));
			height[i] < height[j] ? i++ : j--;
		}
		return res;
    }
};
//一种非常新颖的题型，以前没有接触过
//用两个指针从两端开始向中间靠拢，如果左端线段短于右端，那么左端右移，反之右端左移，
//直到左右两端移到中间重合，记录这个过程中每一次组成木桶的容积，返回其中最大的。
