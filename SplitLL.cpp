int len(ListNode* head){
	int ret=0;
	while(head){
		head=head->next;
		ret++;
	}
	return ret;
}

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
	 	int ln= len(root);
	 	vector<ListNode*> ans(k, NULL);
        if(root==NULL){return ans;}
	 	int size= ln/k;
	 	int bigger = ln%k;
	 	int id=0, cs=1;
	 	ans[id]=root;
	 	ListNode *n=NULL;
	 	while(root->next && id<k-1){
            cout<<(root->val)<<" ";
	 		if(id==k-1){break;}
	 		n=root->next;
	 		if(cs==size && id >=bigger){
	 			root->next=NULL;
	 			id++;
	 			ans[id]=n;
	 			cs=1;
	 		}
	 		else if(cs==size+1 && id<bigger){
	 			root->next=NULL;
	 			id++;
	 			ans[id]=n;
	 			cs=1;
	 		}
	 		else{
	 			cs++;
	 		}
	 		root=n;
	 	}
	 	return ans;     
    }
};