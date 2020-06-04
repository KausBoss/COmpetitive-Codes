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
    pair<int, bool> BB(node* root){
        pair<int, bool> ret;
        //base case
        if(root == NULL){
        	return make_pair(0, true);
        }
        //recursive case
        pair<int, bool> left= BB(root->left);
        pair<int, bool> right= BB(root->right);

        ret.first=max(left.first, right.first) +1;
        int diff = abs(left.first- right.first);
        if(diff<=1){
        	ret.second=true;
        }
        else{
        	ret.second=false;
        }
        return ret;
    }
public:
    bool isBalanced(TreeNode* root) {
        
    }
};