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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
    //  ListNode *ptr1 = list1;
    //  ListNode *ptr2 = list2;

    //  if(ptr1 == NULL){
    //     return ptr2;
    //  }
    //  if(ptr2== NULL){
    //     return ptr1;
    //  }

    //  if(ptr1->val < ptr2->val){
    //     ptr1->next = mergeTwoLists(ptr1->next, ptr2);
    //     return ptr1;
    //  }

    //     else{
    //         ptr2->next = mergeTwoLists(ptr1, ptr2->next);
    //         return ptr2;
    //     }

   ListNode dummy;
        ListNode* tail = &dummy;

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val < ptr2->val) {
                tail->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                tail->next = ptr2;
                ptr2 = ptr2->next;
            }
            tail = tail->next; 
        }

        
        if (ptr1 != nullptr) {
            tail->next = ptr1;
        } else {
            tail->next = ptr2;
        }

        return dummy.next;
    }
};