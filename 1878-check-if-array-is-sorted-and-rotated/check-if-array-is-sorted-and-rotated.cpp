class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
                count++;
        }
        //Check for last element and first element separately because this case is not covered in the loop
        if(nums[n-1]>nums[0])  
            count++;
        if(count<=1)
            return true;
        return false;
    }
};