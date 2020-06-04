int length(ListNode* head){
	int ret=1;
	while(head->next){
		head=head->next;
		ret++;
	}
	return ret;
}
ListNode* reverse(ListNode* head){
	ListNode *p=NULL, *c=head, *n;
	while(c){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	return p;
}
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m==n){return head;}
    	int len=length(head);
    	if(m==1 && n==len){return reverse(head);}

    	if(m==1){
    		ListNode *temp=head, *end;
    		int id=1;
    		while(id<n){id++; temp=temp->next;}
    		end = temp->next;
            temp->next=NULL;
    		ListNode* ret = reverse(head);
    		head->next=end;
    		return ret;
    	}

    	if(n==len){
    		ListNode *temp=head, *sec;
    		int id=1;
    		while(id<m-1){id++; temp=temp->next;}
    		sec=temp->next;
    		temp->next= reverse(sec);
    		return head;
    	}

    	else{
    		ListNode *temp=head, *fe, *end, *sec;
    		int id=1;
    		while(id<m-1){id++; temp=temp->next;}
    		sec=temp->next;
    		fe=temp;
    		temp=temp->next; id++;
    		fe->next=NULL;
    		while(id < n){id++; temp=temp->next;}
    		end=temp->next;
    		temp->next=NULL;
    		fe->next=reverse(sec);
    		sec->next=end;
    		return head;
    	}
    }

};