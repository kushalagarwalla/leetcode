class Solution {
public:
bool isPossibleSolution(vector<int>& weights, int days,int mid)
{
    int weightSum=0,daycount=1;
    for(int i=0;i<weights.size();i++)
    {
        if(weightSum+weights[i]<=mid)
        {
            weightSum+=weights[i];
        }
        else
        {
            daycount++;
            if(daycount>days||weights[i]>mid)
                return false;
            weightSum=weights[i];
        }
    }
    return true;
}
int shipWithinDays(vector<int>& weights, int days) {
        int s=0,e=0,ans=-1;
        for(int i=0;i<weights.size();i++)
        {
            e+=weights[i];
        }
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(isPossibleSolution(weights,days,mid))
            {
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};