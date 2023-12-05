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
    TreeNode* createParentMapping(TreeNode* root, int start, map<TreeNode*,TreeNode*> &nodeToParent)
    {
        //level order travesal of tree
        TreeNode* res=NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty())
        {
            TreeNode* frontNode=q.front();
            q.pop();
            //store start node(if found)
            if(frontNode->val==start)
                res=frontNode;
            
            if(frontNode->left)
            {
                nodeToParent[frontNode->left]=frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right)
            {
                nodeToParent[frontNode->right]=frontNode;
                q.push(frontNode->right);
            }
        }
        return res;
    }
    int infectTree(TreeNode* startNode,map<TreeNode*,TreeNode*> &nodeToParent)
    {
        map<TreeNode*,bool> visited;
        //level order traversal
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode]=true;
        int ans=0;
        while(!q.empty())
        {
            bool flag=0;    //to check if there is an addition to node
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                //process neighbouring nodes
                TreeNode* front=q.front();
                q.pop();
                //process left, right and parent node
                if(front->left && !visited[front->left])
                {
                    flag=1;
                    visited[front->left]=true;
                    q.push(front->left);
                }
                if(front->right && !visited[front->right])
                {
                    flag=1;
                    visited[front->right]=true;
                    q.push(front->right);
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]])
                {
                    flag=1;
                    visited[nodeToParent[front]]=true;
                    q.push(nodeToParent[front]);
                }
            }
            if(flag==1)
                ans++;
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        /*step1: create nodeToParent mapping
          step2: find start node
          step3: burn/infect the tree in min time */
          map<TreeNode*,TreeNode*> nodeToParent;
          TreeNode* startNode=createParentMapping(root,start,nodeToParent);
          return infectTree(startNode,nodeToParent);
    }
};