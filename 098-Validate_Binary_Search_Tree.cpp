class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isvalidcore(root, LONG_MIN, LONG_MAX);
	}
	bool isvalidcore(TreeNode* root, long low, long high) {
		if (root == nullptr) return true;
		if (root->val <= low || root->val >= high) return false;
		return isvalidcore(root->left, low, root->val) && isvalidcore(root->right, root->val, high);
	}
};
//树的问题大部分都可以用递归解决，而递归的时候只需要考虑三个问题：根节点、左子树、右子树
