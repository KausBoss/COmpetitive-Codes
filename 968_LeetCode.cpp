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
class Solution {
	map<TreeNode*, bool> m;
	int ct=0;
	void cam(TreeNode* root){
		//base case
		if(root ==NULL){
			return true;
		}
		//
		bool left = cam(root->left);
		bool right = cam(root->right);
		if()
	}
public:
    int minCameraCover(TreeNode* root) {
        
    }
};