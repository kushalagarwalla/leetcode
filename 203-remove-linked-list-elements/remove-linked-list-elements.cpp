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
    ListNode* removeElements(ListNode* head, int val) {
        //if first element is equal to val
        while(head!=NULL && head->val==val )
        {
            head=head->next;
        }    
        //for remaining cases
        ListNode* curr=head;
        ListNode* prev;
        while(curr!=NULL)
        {
            if(curr->val==val)
            {
                prev->next=curr->next;
            }
           else
            prev=curr;
            
            curr=curr->next;
        }
        return head;
        
    }
};