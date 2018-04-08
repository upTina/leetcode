class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream out;
		seri(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream in(data);
		return dese(in);
	}
	
	TreeNode * dese(istringstream &in) {
		string val;
		in >> val;
		if (val == "#") return nullptr;
		TreeNode* root = new TreeNode(stoi(val));
		root->left=dese(in);
		root->right = dese(in);
		return root;
	}

	void seri(TreeNode*root, ostringstream &out) {
		if (root) {
			out << root->val << ' ';
			seri(root->left, out);
			seri(root->right, out);
		}
		else {
			out << "# ";
		}
	}
};

//两个全新的数据类型，ostringstream和istringstream，可以理解为输入输出缓冲区？全局共同使用的两个变量。
//ostringstream里可以输入进去‘ ’字符，而istringstream往外传的string类型时时候，会忽略空格键，和标准输入cin、输出cout类似
