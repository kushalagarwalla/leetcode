class Solution {
public:
    int firstOccurance(vector<int>& nums, int target)
    {
        int s=0,e=nums.size()-1;
        int m=s+(e-s)/2;
        int first=-1;
        while(s<=e)
        {
            if(nums[m]==target)
            {
                first=m;
                e=m-1;
            }
            else if(nums[m]<target)
            {
                s=m+1;
            }
            else if(nums[m]>target)
            {
                e=m-1;
            }
            m=s+(e-s)/2;
        }
        return first;
    }
     int lastOccurance(vector<int>& nums, int target)
     {
         int s=0;
         int e=nums.size()-1;
         int m=s+(e-s)/2;
        int last=-1;
        while(s<=e)
        {
            if(nums[m]==target)
            {
                last=m;
                s=m+1;
            }
            else if(nums[m]<target)
            {
                s=m+1;
            }
            else if(nums[m]>target)
            {
                e=m-1;
            }
            m=s+(e-s)/2;
        }
        return last;
     }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstOccurance(nums,target));
        ans.push_back(lastOccurance(nums,target));
        return ans;  
    }
};