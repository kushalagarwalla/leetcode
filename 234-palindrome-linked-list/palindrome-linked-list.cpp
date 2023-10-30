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
    ListNode* getMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
         while(fast != NULL && fast-> next != NULL) 
         {
            fast = fast -> next -> next;
            slow = slow -> next;
         }
        return slow;
    }
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;
        while(curr!=NULL)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;

        //Step1: get middle element
        ListNode* middle=getMiddle(head);

        //Step2: reverse the list after the middle element
        ListNode* temp=middle->next;
        middle->next=reverseList(temp);

        //step3: compare
        ListNode* head1=head;
        ListNode* head2=middle->next;
        while(head2!=NULL)
        {
            if(head1->val != head2->val)
                return false;
            else
            {
                head1=head1->next;
                head2=head2->next;
            }
        }

        //step4: reverse the list after the middle element
        temp=middle->next;
        middle->next=reverseList(temp);

        return true;
    }
};