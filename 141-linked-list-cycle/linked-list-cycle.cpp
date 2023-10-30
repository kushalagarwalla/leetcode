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
    bool hasCycle(ListNode *head) {
        /* Approach 1: Use Map
        if(head==NULL||head->next==NULL)
            return false;

        map<ListNode*,bool> visited;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(visited[curr]==true)
                return true;
            
            visited[curr]=true;
        }
        return false;
        */
        //Approach 2: Floyd's Cycle Finding Algorithm/Hare-Tortoise algorithm
        if(head==NULL||head->next==NULL)
            return false;

        ListNode* slow= head;
        ListNode* fast= head;
        while(slow!=NULL && fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
                fast=fast->next;

            slow=slow->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};