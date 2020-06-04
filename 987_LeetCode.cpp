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
	vector<vector<int>> ans;
	map<int,set<pair<int,int>>> m;
	void Pre(TreeNode* root, int i, int j){
		//base case
		if(root==NULL){
			return;
		}
		//recursive case
		m[i].insert(make_pair(j,root->val));
		Pre(root->left, i-1, j+1);
		Pre(root->right, i+1, j+1);
	}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        Pre(root, 0, 0);
        for(auto x:m){
        	vector<int> temp;
        	for(auto it=x.second.begin(); it!=x.second.end(); it++){
        		temp.push_back(it->second);
        	}
        	ans.push_back(temp);
        	temp.clear();
        }
        return ans;
    }
};