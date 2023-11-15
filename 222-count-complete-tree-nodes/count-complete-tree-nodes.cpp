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
    void solve(TreeNode* root, int &count)
    {
        if(root!=NULL)
        {
            solve(root->left,count);
            if((root->left!=NULL && root->right!=NULL) || (root->left==NULL && root->right==NULL) || (root->left!=NULL && root->right==NULL) )
                count++;
            solve(root->right,count);
        }
    }
    int countNodes(TreeNode* root) {
        int count=0;
        solve(root,count);
        return count;
    }
};