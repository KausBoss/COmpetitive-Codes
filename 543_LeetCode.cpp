class Solution {
	pair<int, int> dia(TreeNode* root){
		//base case
		if(root ==NULL){
			return make_pair(0,0);
		}
		//recursive case
		pair<int, int> v;
		v.first= max(dia(root->left).first, dia(root->right).first)+1;
		v.second = max(dia(root->left).first + dia(root->right).first,
		max(root->left).second, dia(root->right).second);
		return v; 
	}
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dia(root).second;
    }
};