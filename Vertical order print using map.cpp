#include <iostream>
#include <map>
#include <vector>
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

map <int, vector<int>> travel;

void verital_map(Node* root, int longitude){
	//base case
	if(root == NULL){
		return;
	}
	//recursive case
	travel[longitude].push_back(root->data);
	verital_map(root->left, longitude-1);
	verital_map(root->right, longitude+1);
}

int main(int argc, char const *argv[]){
	Node* root = new Node(1);
	
	root->left = new Node(2);
	root->right = new Node(3);

	root->left->left = new Node(4);
	root->left->right = new Node(5);

	root->right->left = new Node(6);
	root->right->right = new Node(7);

	root->right->right->right = new Node(9);
	root->left->right->right = new Node(8);

	verital_map(root, 0);
	for(auto x:travel){
		for(int y:x.second){
			cout<<y<<" ";
		}
		cout<<endl;
	}
}