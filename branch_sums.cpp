using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

vector<int> branchSums(BinaryTree *root) {
	if (root == nullptr) {
		return {};
	}
	if (root->left == nullptr && root->right == nullptr) {
		return {root->value};
	}
	vector<int> left_sums = branchSums(root->left);
	vector<int> right_sums = branchSums(root->right);
	
	for (int i = 0; i < left_sums.size(); ++i) {
		left_sums[i] += root->value;
	}
	for (int i = 0; i < right_sums.size(); ++i) {
		right_sums[i] += root->value;
	}
	
	vector<int> combined_vec = left_sums;
	combined_vec.insert(combined_vec.end(), right_sums.begin(), right_sums.end());
	return combined_vec;
}
