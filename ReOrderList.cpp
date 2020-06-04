ListNode* middle(ListNode* head){
	ListNode *slow=head, *fast=head->next;
	while(fast && fast->next){
		slow=slow->next;
		fast= fast->next->next;
	}
	return slow;
}

ListNode* reverse(ListNode* head){
	ListNode *p=NULL, c=head, n=NULL;
	while(c){
		n=c->next;
		c->next = p;
		p=c;
		c=n;
	}
	return p;
}
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *mid = middle(head);
        ListNode *j= reverse(mid->next);
        mid->next=NULL;
        ListNode *i=head, in, jn;
        while(i){
        	in=i->next;
        	i->next=j;
        	i=in;
        	jn=j->next;
        	j->next=i;
        	j=jn;
        }
        return head;
    }
};