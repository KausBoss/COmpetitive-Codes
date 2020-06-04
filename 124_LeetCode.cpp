/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//pair<max sum, sum current>
class Solution {
public:
	pair<int, int> MX(TreeNode* root){
		//base case
		if(root == NULL){
			return make_pair(0,0);
		}
		//recurisve case
		pair<int, int> left= MX(root->left);
		pair<int, int> right=MX(root->right);
		int d=root->data;
		pair<int,int> p;
		p.first = max(left.first, right.first);
		if(left.second+d<0  && right.second+d<0){
			p.second=0;
			return p;
		}
		if(left.second + d + right.second > p.first){
			p.first = left.second + d + right.second;
		}
		p.second = max(left.second, right.second) + d;
		return p;

	}
    int maxPathSum(TreeNode* root) {
        return MX(root).first;
    }
};