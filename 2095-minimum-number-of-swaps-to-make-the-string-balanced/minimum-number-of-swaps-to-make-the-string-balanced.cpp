class Solution {
public:
    int minSwaps(string s) {
        //remove valid paranthesis
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='[')
                st.push(s[i]);
            else
            {
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }

        int openCount=0,closeCount=0;
        while(!st.empty())
        {
            if(st.top()=='[')
                openCount++;
            else
                closeCount++;

            st.pop();
        }
        if(openCount%2==0)
            return openCount/2;
        else
            return (openCount+1)/2;
    }
};