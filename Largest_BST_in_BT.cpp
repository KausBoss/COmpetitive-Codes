#include <iostream>
#include <climits>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* MakeTree(int pre[], int in[], int s, int e){
    static int i = 0;
    //base case
    if(s > e){
        return NULL;
    }
    //recursive case
    Node* root = new Node(pre[i]);
    int pt = s;
    while(in[pt] != pre[i]){
        pt++;
    }
    i++;
    root->left = MakeTree(pre, in, s, pt-1);
    root->right = MakeTree(pre, in, pt+1, e);
    return root;
}

class ret{
public:
    bool IsBST;
    int max_size;
    int min_size;
    int dist;
    ret(){}
    ret(bool IsBST, int max_size, int min_size, int dist){
    	this->IsBST=IsBST;
    	this->max_size=max_size;
    	this->min_size=min_size;
    	this->dist=dist;
    }
};
int ans =INT_MIN;

ret MaxBST(Node* root){
	ret n;
	//base case
	if(root==NULL){
		ret n(1,INT_MIN, INT_MAX, 0);
		return n;
	}
	if(root->left==NULL && root->right==NULL){
		ret n(1, root->data, root->data, 1);
		return n;
	}
	//recursive case
	ret left = MaxBST(root->left);
	ret right= MaxBST(root->right);

	if(left.IsBST && right.IsBST && left.max_size <= root->data && right.min_size >=root->data){
		ret n;
		n.IsBST=true;
		n.max_size = min(left.min_size, min(right.min_size, root->data));
		n.min_size = max(left.max_size, max(right.max_size, root->data));
		n.dist = left.dist + right.dist +1;
	}
	else{
		ret n(0, INT_MIN, INT_MAX, 0);
	}
	ans=max(ans, n.dist);
	return n;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    int n, pre[1000], in[1000];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>pre[i];
    }
    for(int i=0; i<n; i++){
        cin>>in[i];
    }
    Node* Tree = MakeTree(pre, in, 0, n-1);
    MaxBST(Tree);
    cout<<ans;
}