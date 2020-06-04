ListNode* floyd(ListNode* head, ListNode* comm){
	while(head!=comm){
		head=head->next;
		comm= comm->next;
	}
	return comm;
}


ListNode* haicycle(ListNode* head){
	ListNode *slow=head, *fast=head;
	while(fast!=NULL && fast->next!=NULL){
    	fast = fast->next->next;
    	slow = slow->next;
    	if(fast == slow){
    		return floyd(head, fast);
    	}
    }
    return NULL;
}



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	return haicycle(head);
    	
    }
};