class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s=0,e=nums.size()-1;
        vector<int> ans;
       while(s<=e)
        {
             int sqr1=nums[s]*nums[s];
             int sqr2=nums[e]*nums[e];
            if(sqr1>sqr2)
            {
                ans.push_back(sqr1);
                s++;
            }
            else
            {
                ans.push_back(sqr2);
                e--;
            }
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};