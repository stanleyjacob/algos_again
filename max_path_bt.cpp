#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};

std::tuple<int, int> maxPathHelper(BinaryTree *tree) {
	if (tree == NULL) {
		return std::make_tuple(0, INT_MIN);
	}
	
	int mps_branch_left;
	int mps_left;
	std::tie(mps_branch_left, mps_left) = maxPathHelper(tree->left);
	
	int mps_branch_right;
	int mps_right;
	std::tie(mps_branch_right, mps_right) = maxPathHelper(tree->right);
	
	int mps_branch = tree->value;
	mps_branch = max(mps_branch, tree->value + mps_branch_right);
	mps_branch = max(mps_branch, tree->value + mps_branch_left);
	
	int mps = max(mps_branch, tree->value + 
									 mps_branch_left + mps_branch_right);
	mps = max(mps, mps_left);
	mps = max(mps, mps_right);
	
	return make_tuple(mps_branch, mps);
}

int maxPathSum(BinaryTree tree) {
  int max_branch, max_tree;
  std::tie(max_branch, max_tree) = maxPathHelper(&tree);
  return max_tree;
}
