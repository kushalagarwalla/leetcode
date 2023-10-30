class Solution {
public:
    char toLower(char ch)
    {
        if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9'))
            return ch;
        else
        {
            char temp=ch-'A'+'a';
            return temp;
        }
    }
    bool isValid(char ch)
    {
        if((ch>='a'&&ch<='z')||(ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(isValid(s[i]))
                temp.push_back(toLower(s[i]));
        }
        int start=0,end=temp.length()-1;
        while(start<=end)
        {
            if(temp[start]!=temp[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};