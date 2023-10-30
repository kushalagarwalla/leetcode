class Solution {
public:
    bool isPossibleSolution(vector<int>& position, int m,int mid)
    {
        int ballCount=1,lastPos=position[0];
        for(int i=0;i<position.size();i++)
        {
            if(position[i]-lastPos>=mid)
            {
                ballCount++;
                if(ballCount==m)
                {
                    return true;
                }
                lastPos=position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=0,ans=0;
        int e=INT_MIN;
        for(int i=0;i<position.size();i++)
            e=max(e,position[i]);
        int mid=s+(e-s)/2;
        while(s<=e)
        {
            if(isPossibleSolution(position,m,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};