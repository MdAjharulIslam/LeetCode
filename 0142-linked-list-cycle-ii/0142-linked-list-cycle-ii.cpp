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
    ListNode *detectCycle(ListNode *head) {
        while(head==NULL ||( head->next==NULL)){
            return NULL;
        }
        
        ListNode *slow =head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
      fast=fast->next->next;
            if(slow==fast)
                break;
            
        }
        if(slow!=fast)
            return NULL;
        
        
        ListNode *a=head;
        while(a!=slow){
           slow= slow->next;
            a=a->next;
        }
        return slow;
    }
};