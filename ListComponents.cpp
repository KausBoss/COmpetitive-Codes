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
    int numComponents(ListNode* head, vector<int>& G) {
        int freq[10004]={0};
        for(int i=0; i<G.size(); i++){
            freq[G[i]]++;
        }
        int ans=0;
        while(head->next){
            if(freq[head->val]!=0 && freq[head->next->val]==0){
            	ans++;
            }
            head=head->next;
        }
        if(freq[head->val] !=0 ){ans++;}
        return ans;
    }
};