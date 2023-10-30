class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0,c=0;
        while(c<nums.size())
        {
            if(nums[c]!=0)
            {
                swap(nums[s],nums[c]);
                s++;
            }
            c++;
        }

    }
};