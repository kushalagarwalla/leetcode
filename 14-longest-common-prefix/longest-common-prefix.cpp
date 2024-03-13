class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //Approach 1: take characters of first string and compare it with all the remaining string
        string ans="";
        int n=strs.size();
        //for traversing all the characters of first string
        for(int i=0;i<strs[0].length();i++)
        {
            char ch=strs[0][i];

            bool match=true;

            //for comparing ch with rest of the string
            for(int j=0;j<n;j++)
            {
                //not match
                if(strs[j].size() < i || strs[j][i]!=ch)
                {
                    match= false;
                    break;
                }
            }
            if(match==false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};