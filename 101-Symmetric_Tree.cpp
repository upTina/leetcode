class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return isSymCore(root->left, root->right);
	}
	bool isSymCore(TreeNode*root1, TreeNode*root2) {
		if (root1 == nullptr&&root2 == nullptr) return true;
		if (root1 == nullptr || root2 == nullptr) return false;
		if (root1->val != root2->val) return false;
		return isSymCore(root1->left, root2->right) && isSymCore(root1->right, root2->left);
	}
};
//树的问题一般用递归求解。求解一般只需要考虑三个问题：根节点、左子树、右子树
