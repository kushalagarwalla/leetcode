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

    TreeNode* solve(vector<int> preorder, vector<int> inorder, int &index, int inorderStart, int inorderEnd, int size, map<int,int> &nodeToIndex)
    {
        //base case
        if(index>=size || inorderStart>inorderEnd)
            return NULL;
        //create root element
        int element=preorder[index];
        TreeNode* root=new TreeNode(element);
        index++; //move to next element
        //find root position in inorder array
        int position= nodeToIndex[element];
        //recursive calls for left and right
        root->left=solve(preorder,inorder,index,inorderStart,position-1,size,nodeToIndex);
        root->right=solve(preorder,inorder,index,position+1,inorderEnd,size,nodeToIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int n=inorder.size();
        map<int,int> nodeToIndex;
        //create map for storing the index of nodes present in inorder array
        createMap(nodeToIndex,inorder,n);
        TreeNode* ans= solve(preorder,inorder,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};