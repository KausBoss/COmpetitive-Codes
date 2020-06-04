class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){return head;}
        for(Node* n;n; n=n->next){
        	if(n->child){
        		Node* next=n->next;
        		n->next=n->child;
        		n->child=NULL;
        		n->next->prev=n;
        		Node *p=n->next;
        		while(p->next){p=p->next;}
        		p->next=next;
        		if(next){next->prev=p;}
        	}
        	n=n->next;
        }
        return head;
    }
};

Node* flatten(Node* head) {
	for (Node* h = head; h; h = h->next)
	{
		if (h->child){
			Node* next = h->next;
			h->next = h->child;
			h->next->prev = h;
			h->child = NULL;
			Node* p = h->next;
			while (p->next) p = p->next;
			p->next = next;
			if (next) next->prev = p;
		}
	}
	return head;
}