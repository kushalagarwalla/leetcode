class Solution {
public:
    bool isPossibleSolution(vector<int>& nums, int k, int mid)
    {
        int sum=0,arrayCount=1;
        for(int i=0;i<nums.size();i++)
        {
            if((sum+nums[i])<=mid)
            {
                sum+=nums[i];
            }
            else
            {
                arrayCount++;
                if(arrayCount>k || nums[i]>mid)
                    return false;
                sum=nums[i];
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        int start=0,end=sum;
        int ans=-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(isPossibleSolution(nums,k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};