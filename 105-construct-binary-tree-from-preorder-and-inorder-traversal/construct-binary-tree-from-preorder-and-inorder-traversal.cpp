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
    int findPosition(int element,vector<int> inorder,int size)
    {
        for(int i=0;i<size;i++)
        {
            if(inorder[i]==element)
                return i;
        }
        return -1;
    }

    TreeNode* solve(vector<int> preorder, vector<int> inorder, int &index, int inorderStart, int inorderEnd, int size)
    {
        //base case
        if(index>=size || inorderStart>inorderEnd)
            return NULL;
        //create root element
        int element=preorder[index];
        TreeNode* root=new TreeNode(element);
        index++; //move to next element
        //find root position in inorder array
        int position= findPosition(element,inorder,size);
        //recursive calls for left and right
        root->left=solve(preorder,inorder,index,inorderStart,position-1,size);
        root->right=solve(preorder,inorder,index,position+1,inorderEnd,size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        int n=inorder.size();
        TreeNode* ans= solve(preorder,inorder,preOrderIndex,0,n-1,n);
        return ans;
    }
};