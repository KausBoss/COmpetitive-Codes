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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small_head=NULL, *big_head=NULL, *bi=NULL, *si=NULL;
        ListNode *temp=head, *n;
        while(temp){
        	n = temp->next;
        	if(temp->val < x){
        		if(small_head==NULL){
        			small_head=temp;
        			si=temp;
        		}
        		else{
        			si->next=temp;
        			si=si->next;
        		}
        	}
        	else{
        		if(big_head==NULL){
        			big_head=temp;
        			bi=temp;
        		}
        		else{
        			bi->next=temp;
        			bi=bi->next;
        		}
        	}
        	temp->next=NULL;
            temp=n;
        }
        if(small_head==NULL){return big_head;}
        si->next = big_head;
        return small_head;
    }
};