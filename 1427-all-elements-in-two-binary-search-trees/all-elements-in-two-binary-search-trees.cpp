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
    void inorder(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);

        vector<int> ans(v1.size()+v2.size());
        int i=0,j=0,k=0;
        while(i<v1.size() && j<v2.size())
        {
            if(v1[i]<v2[j])
                ans[k++]=v1[i++];
            else
                ans[k++]=v2[j++];
        }
        while(i<v1.size())
        {
            ans[k++]=v1[i++];
        }
        while(j<v2.size())
        {
            ans[k++]=v2[j++];
        }
        return ans;
    }
};