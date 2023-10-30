class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int x=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                if(!(x^nums[i]))
                {
                    ans.push_back(nums[i]);
                    i++;
                    if(i<nums.size())
                    x=nums[i];
                    else break;
                }
                else x=nums[i];
            }
        return ans; 
    } 
};