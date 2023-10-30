class Solution {
public:
    void Solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans)
    {
        //base case
        if(index>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        //exclude element
        Solve(nums,output,index+1,ans);

        //include element
        output.push_back(nums[index]);
        Solve(nums,output,index+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index=0;
        Solve(nums,output,index,ans);
        return ans;
    }
};