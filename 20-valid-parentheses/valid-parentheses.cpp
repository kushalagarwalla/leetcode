class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            //if s[i] is opening bracket then push
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                st.push(s[i]);
            }
            //if s[i] is closing bracket, then check top of stack and pop
            else
            {
                if(!st.empty())
                {
                    char ch=st.top();
                    if((ch=='{' && s[i]=='}')||(ch=='(' && s[i]==')')||(ch=='[' && s[i]==']'))
                        st.pop();
                    else
                        return false;
                }
                else
                    return false;
            }

        }
        if(st.empty())
            return true;
        else
            return false;
    }
};