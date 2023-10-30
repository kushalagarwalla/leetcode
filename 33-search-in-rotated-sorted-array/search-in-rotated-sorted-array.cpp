class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<e)
        {
            if(nums[mid]>=nums[0])
            {
                s=mid+1;
            }
            else
            e=mid;
            mid=s+(e-s)/2;
        }
        return s;
    }  
    int BinarySearch(vector<int>& nums,int s,int e,int k)
    {
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid]==k)
            {
                return mid;
            }
            else if(nums[mid]>k)
            {
                e=mid-1;
            }
            else if(nums[mid]<k)
            {
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=findPivot(nums);
        int n=nums.size();
        if(target>=nums[pivot] && target<=nums[n-1])
        {
            return BinarySearch(nums,pivot,n-1,target);
        }
        else
             return BinarySearch(nums,0,pivot,target);
    }
};