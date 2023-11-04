class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        s.push(0);
        int n=prices.size();
         vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            int val=prices[i];
            while(!s.empty() && s.top()>val)
            {
                s.pop();
            }
            ans[i]=val-s.top();
            s.push(val);
        }
        return ans;
    }
};