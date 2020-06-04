class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
    	ListNode* oddhead=head;
    	ListNode* evenhead= head->next;
    	ListNode *c=head, *p=NULL, *n=NULL;
    	int jump=0;
    	while(c && c->next){
    		n=c->next;
    		c->next=n->next;
    		p=c;
    		c=n;
    		jump++;
    	}
    	if(jump%2==1){p->next=evenhead;}
    	else{c->next=oddhead;}
    	return oddhead;
    }
};