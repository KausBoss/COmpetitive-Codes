#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data){
		this->data = data;
		left = right = NULL;
	}
};

Node* BuildTree(){
	int d;
	cin>>d;
	//base case
	if(d == -1){
		return NULL;
	}
	//recursive case
	Node* root = new Node(d);
	root->left = BuildTree();
	root->right = BuildTree();
	return root; 
}

void PrintTree(Node* root){
	//base case
	if(root == NULL){
		return;
	}
	//recursive case
	cout<<root->data<<" ";
	PrintTree(root->left);
	PrintTree(root->right);
}

void PrintInOrder(Node* root){
	//base case
	if(root == NULL){
		return;
	}
	//recursive case
	PrintTree(root->left);
	cout<<root->data<<" ";
	PrintTree(root->right);
}

int Height(Node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recusrive case
	return max(Height(root->left), Height(root->right)) + 1;
}

void PrintAtLevel(int l, Node* root){
	//base case
	if(root == NULL){
		return;
	}
	if(l == 1){
		cout<<root->data<<" ";
		return;
	}
	//recursive case
	PrintAtLevel(l-1, root->left);
	PrintAtLevel(l-1, root->right);
	return;
}

void LevelOrderPrint(Node* root){
	int h = Height(root);

	for(int i=1; i<=h; i++){
		PrintAtLevel(i, root);
		cout<<endl;
	}
}

void BFS(Node* root){
	queue<Node*> Q;
	Q.push(root);
	Q.push(NULL);
	while(!Q.empty()){
		if(Q.front() == NULL){
			Q.pop();
			cout<<endl;
			if(!Q.empty()){
				Q.push(NULL);
			}
		}
		else{
			Node* temp = Q.front();
			Q.pop();
			cout<<temp->data<<" ";
			if(temp->left != NULL){
				Q.push(temp->left);
			}
			if(temp->right != NULL){
				Q.push(temp->right);
			}
		}
	}
}

int CountNodes(Node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	return CountNodes(root->left) + CountNodes(root->right) + 1;
}

int diameterSlow(Node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	//recursive case
	int left_height = Height(root->left);
	int right_height = Height(root->right);
	int op1 = left_height + right_height;
	int op2 = diameterSlow(root->left);
	int op3 = diameterSlow(root->right);
	return max(op1, max(op2, op3)); 
}

pair<int, int> dia(Node* root){
	//base case
	if(root == NULL){
		return {0,0};
	}
	//recursive case
	pair<int, int> v;
	v.first = max(dia(root->left).first, dia(root->right).first)+1;
	v.second = max(dia(root->left).first + dia(root->right).first, 
		           max(dia(root->left).second, dia(root->right).second));
	return v;
}

Node* balancedBST(int ar[], int s, int e){
	//base case
	if(s > e){
		return NULL;
	}
	//recursive case
	int mid = (s+e)/2;
	Node* root = new Node(ar[mid]);
	root->left = balancedBST(ar, s, mid-1);
	root->right =balancedBST(ar, mid+1, e);
	(ar, mid+1, e);
	return root;
}


Node* MakeTreeFromPreandInOrder(int pre[], int In[], int s, int e){
	static int i =0; //initialised only once
	//base case
	if(s > e){
		return NULL;
	}
	//recursive case
	Node* root = new Node(pre[i]);
	int index;
	for(int j=s; j<=e; j++){
		if(In[j] == pre[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = MakeTreeFromPreandInOrder(pre, In, s, index-1);
	root->right= MakeTreeFromPreandInOrder(pre, In, index+1, e);
	return root;
}
//in pair<int, int>. first int is the max sum of the path, second sum is the max sum ans till now
pair<int, int> MaxSumPath(Node* root){
	//base case
	if(root == NULL){
		return {0,0};
	}
	//recursive case
	pair<int, int> ret;
	pair<int, int> ls = MaxSumPath(root->left);
	pair<int, int> rs = MaxSumPath(root->right);

	int max_sum = max(ls.second, rs.second);
	int d = root->data;
	ret.second = max_sum;

	if(ls.first + d < 0 && rs.first + d < 0){
		ret.first =0;
		return ret;
	}

	if(d + ls.first + rs.first > max_sum){
		ret.second = d + ls.first + rs.first;
	}

	ret.first = max(ls.first, rs.first) + d;
	return ret;
}

int main(){
	//Node* tree = BuildTree();
	//PrintTree(tree);
	//cout<<Height(tree);
	//LevelOrderPrint(tree);
	//BFS(tree);
	//cout<<CountNodes(tree);
	//cout<<diameterSlow(tree);
	//cout<<dia(tree).second;
	//int ar[] = {1, 2, 3, 4, 5, 6};
	//int n = sizeof(ar)/sizeof(int);
	//Node* tree = balancedBST(ar, 0, n-1);
	//BFS(tree);
	//PrintTree(tree);
	//cout<<endl;
	//PrintInOrder(tree);
	//int pre[] = {3, 1, 2, 5, 4, 6};
	//int In[] = {1, 2, 3, 4, 5, 6};
	//Node* tree = MakeTreeFromPreandInOrder(pre, In, 0, 5);
	//BFS(tree);
	Node* tree = BuildTree();
	cout<<MaxSumPath(tree).second;
}