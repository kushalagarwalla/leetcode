class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        reverse(nums.begin(),nums.end());
        //(k%nums.size()) is done in place of k to make edge cases work
        reverse(nums.begin(),nums.begin()+(k%nums.size())); 
        reverse(nums.begin()+(k%nums.size()),nums.end());
    
    }
};