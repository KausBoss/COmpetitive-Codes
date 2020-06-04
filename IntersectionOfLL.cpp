
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *A=headA, *B=headB;
        while(A!=B){
        	A= A?A->next:headA;
        	B= B?B->next:headB;
        }
        return A;
    }
};