ListNode* MidPoint(ListNode* head){
	ListNode *slow=head, *fast=head->next;
	while(fast && fast->next){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}

ListNode * Merge(ListNode *a, ListNode *b){
	if(a==NULL){return b;}
	if(b==NULL){return a;}

	//recursive case
	ListNode *c=NULL;
	if(a->val < b->val){
		c=a;
		c->next = Merge(a->next, b);
	}
	else{
		c=b;
		c->next = Merge(a, b->next);
	}
	return c;
}


ListNode* MergeSort(ListNode* head){
	//base case
	if(head==NULL || head->next==NULL){
		return head;
	}
	//recusrive case
	//finding the mid point
	ListNode *mid= MidPoint(head);
	ListNode *a=head;
	ListNode *b=mid->next;
	mid->next=NULL;

	//Recursive Merge Sort
	a = MergeSort(a);
	b = MergeSort(b);

	//merge a and b
	ListNode *c=merge(a, b);
	return c;
}

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return MergeSort(head);
    }
};