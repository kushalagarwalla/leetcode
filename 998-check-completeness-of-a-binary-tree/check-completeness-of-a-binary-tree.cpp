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
    int getCount(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+getCount(root->left)+getCount(root->right);
    }
    bool isCBT(TreeNode* root, int TotalNodeCount, int index)
    {
        if(root==NULL)
            return true;
        if(index > TotalNodeCount)
            return false;

        bool left=isCBT(root->left,TotalNodeCount,2*index);
        bool right=isCBT(root->right,TotalNodeCount,2*index+1);
        return left && right;
    }
    bool isCompleteTree(TreeNode* root) {
        int TotalNodeCount= getCount(root);
        return isCBT(root,TotalNodeCount,1);
    }
};