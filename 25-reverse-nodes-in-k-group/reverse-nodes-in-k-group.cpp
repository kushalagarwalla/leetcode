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
            curr=curr->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head==NULL)
            return NULL;
        if( getLength(head)<k)  //Case in which remaining length < k
            return head;
        //Reverse k nodes
        int count=0;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward;
        while(curr!=NULL && count<k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        //Recursively reverse all the nodes
        if(forward!=NULL)
        {
            head->next=reverseKGroup(forward,k);
        }

        //Return head of reverse list
        return prev;

    }
};