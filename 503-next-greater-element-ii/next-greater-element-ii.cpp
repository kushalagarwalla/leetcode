class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n=nums.size();
        vector<int> ans(n);
        
        for(int i=2*n-1;i>=0;i--)
        {
            int val=nums[i%n];
            while(!s.empty() && s.top()<=val)
            {
                s.pop();
            }
            if(i<n)
            {
                //handle -1 case separately 
                if(s.empty())
                    ans[i]=-1;
                else
                    ans[i]=s.top();
            }
            s.push(val);
        }
        return ans;
    }
};