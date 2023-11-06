class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //curr_min indicates the minimum price of the stock
        int curr_min=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++)
        {
            curr_min=min(curr_min,prices[i]);
            profit=max(profit,prices[i]-curr_min);
        }
        return profit;
    }
};