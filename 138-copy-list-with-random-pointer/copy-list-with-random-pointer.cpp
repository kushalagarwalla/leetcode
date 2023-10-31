/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head, Node* &tail, int data)
    {
        Node* temp=new Node(data);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    Node* copyRandomList(Node* head) {
        // Approach 1: Using Map
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* curr=head;
        //step 1: create a copy of the list
        while(curr!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,curr->val);
            curr=curr->next;
        }
        //step 2: store mappping of original node to clone node
        unordered_map<Node*,Node*> oldToNew;
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL)
        {
            oldToNew[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        //step 3: Using the map point the random node in the new list
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL)
        {
            cloneNode->random=oldToNew[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
        
        /* Approach 2: 
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* curr=head;
        //step 1: create a copy of the list
        while(curr!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,curr->val);
            curr=curr->next;
        }

        //step 2: add cloneNodes in between Original list
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL)
        {
            Node* next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;

            next=cloneNode;
            cloneNode->next=originalNode;
            cloneNode=next;
        }

        //step 3: copy random pointer
        Node* temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                //if temp->random is NULL, then it will not have next.
                //In this case we will set cloneNode's random as NULL
                temp->next->random= temp->random ? temp->random->next : temp->random;
            }
            temp=temp->next->next;
        }

        //step 4: Revert step2 changes
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL && cloneNode!=NULL)
        {
            originalNode->next=cloneNode->next;
            originalNode=originalNode->next;

            if(originalNode!=NULL)
            {
                cloneNode->next=originalNode;
            }
            cloneNode=cloneNode->next;
        }

        //step5: return ans;
        return cloneHead;
        */
    }
};