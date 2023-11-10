class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> count;
        queue<char>q;
        for(int i=0;i<s.length();i++)
        {
            q.push(s[i]);
            count[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            char ch=q.front();
            if(count[ch]>1)
                q.pop();
        }
        if(q.empty())
            return -1;
        char ch= q.front();
        int ans;
        for(int i=0;i<s.length();i++)
        {
            if(ch==s[i])
               {
                    ans= i;
                    break;
               }
        }
        return ans;
    }
};