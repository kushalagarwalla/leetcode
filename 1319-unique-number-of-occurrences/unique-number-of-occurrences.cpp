class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<arr.size())
        {
            int count=1;
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[i]==arr[j])
                count++;
                else
                break;
            }
            ans.push_back(count);
            i+=count;
        } 
       i=0;
       sort(ans.begin(),ans.end());
       for(i=0;i<ans.size()-1;i++) 
       {
           if(ans[i]==ans[i+1])
           return false;
       }
       return true;
    }
};