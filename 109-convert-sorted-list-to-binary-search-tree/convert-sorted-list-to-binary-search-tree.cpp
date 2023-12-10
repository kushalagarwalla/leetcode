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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr1=head;
        ListNode* curr2=head;
        while(curr1!=NULL && curr1->next!=NULL)
        {
            prev=curr2;
            curr2=curr2->next;
            curr1=curr1->next->next;
        }
        prev->next=NULL;
        return curr2;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        if (!head->next)
            return new TreeNode(head->val);
        ListNode* mid=findMid(head);
        TreeNode* root=new TreeNode(mid->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(mid->next);
        return root;
    }
};