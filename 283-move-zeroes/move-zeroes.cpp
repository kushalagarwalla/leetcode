class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start=0,curr=0;
        while(curr<nums.size())
        {
            if(nums[curr]!=0)
            {
                swap(nums[curr],nums[start]);
                start++;
            }
            curr++;
        }
    }
};