/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return 0;
        }
        
        //step 1 find the middle
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!= NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //step 2 revarse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        ListNode* secondHalf = prev;
        
        
           // Step 3: Calculate the maximum twin sum.
        int maxSum = 0;
        ListNode* firstHalf = head;
        while (secondHalf != NULL) {
            maxSum = max(maxSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Return the result.
        return maxSum;
    }
};