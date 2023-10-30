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
    int getLength(ListNode* head)
    {
        int len=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        
       /* Approach 1: Twice Traversal
       int mid=(getLength(head)/2)+1;
        ListNode* curr=head;
        for(int i=1;i<mid;i++)
        {
            curr=curr->next;
        }
        return curr;*/

        //Approach 2: Single Traversal
        ListNode* curr1=head->next;
        ListNode* curr2=head;
        while(curr1!=NULL)
        {
            curr1=curr1->next;
            if(curr1!=NULL)
            {
                curr1=curr1->next;
            }
            curr2=curr2->next;
        }
        return curr2;
    }
};