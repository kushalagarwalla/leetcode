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
 struct info{
     int maxi;
     int mini;
     bool isBST;
     int sum;
 };
class Solution {
public:
    info solve(TreeNode* root, int &ans)
    {
        //base case
        if(root==NULL)
            return {INT_MIN,INT_MAX,true,0};
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        info currNode;
        currNode.sum=left.sum + right.sum + root->val;
        currNode.maxi= max(root->val,right.maxi);
        currNode.mini= min(root->val,left.mini);
        //check if node is BST
        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
        {
            currNode.isBST=true;
        }
        else
        {
            currNode.isBST=false;
        }
        //update ans;
        if(currNode.isBST)
        {
            ans=max(ans,currNode.sum);
        }
        return currNode;
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;
        info temp=solve(root,ans);
        return ans;
    }
};