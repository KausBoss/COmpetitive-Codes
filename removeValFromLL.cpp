/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        ListNode *temp=head->next, *prev=head;
        while(temp){
        	if(temp->val == val){
        		prev->next=temp->next;
        		delete temp;
                temp=prev->next;
        	}
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        if(head->val == val){head=head->next;}
        return head;
    }
};