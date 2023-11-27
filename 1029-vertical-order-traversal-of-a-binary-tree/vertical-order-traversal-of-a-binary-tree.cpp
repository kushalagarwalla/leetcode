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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        
        //create a map to store horizontal and level of each node
        /*   HD     lvl
             ^       ^                        
             |       |                 */
        map<int,map<int,multiset<int>>> v;
        //create a queue for level order traversal of nodes
        /*                         HD  lvl
                                    ^   ^
                                    |   |                 */
        queue<pair<TreeNode*, pair<int,int>>>q;
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty())
        {
            pair<TreeNode*, pair<int,int>>temp=q.front();
            q.pop();
            TreeNode* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;
            v[hd][lvl].insert(frontNode->val);
            if(frontNode->left)
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            if(frontNode->right)
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
        }
        for(auto i: v)
        {
            vector<int> Node;
            for(auto j: i.second)
            {
                Node.insert(Node.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(Node);
        }
        return ans;
    }
};