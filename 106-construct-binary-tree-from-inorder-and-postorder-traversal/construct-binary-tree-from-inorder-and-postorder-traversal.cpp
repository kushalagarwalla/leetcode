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
    void createMap(map<int,int> &nodeToIndex,vector<int> inorder,int size)
    {
        for(int i=0;i<size;i++)
            nodeToIndex[inorder[i]]=i;
    }

    TreeNode* solve(vector<int> postorder, vector<int> inorder, int &index, int inorderStart, int inorderEnd, int size, map<int,int> &nodeToIndex)
    {
        //base case
        if(index < 0 || inorderStart>inorderEnd)
            return NULL;
        //create root element
        int element=postorder[index];
        TreeNode* root=new TreeNode(element);
        index--; //move to previous element
        //find root position in inorder array
        int position= nodeToIndex[element];
        //recursive calls for right and left
        root->right=solve(postorder,inorder,index,position+1,inorderEnd,size,nodeToIndex);
        root->left=solve(postorder,inorder,index,inorderStart,position-1,size,nodeToIndex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n=inorder.size();
        int postOrderIndex=n-1;
        map<int,int> nodeToIndex;
        //create map for storing the index of nodes present in inorder array
        createMap(nodeToIndex,inorder,n);
        TreeNode* ans= solve(postorder,inorder,postOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};