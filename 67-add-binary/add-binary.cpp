class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        string s="";
        int carry=0;
        while(i>=0 || j>=0 || carry>0)
        {
            int val1=0,val2=0;
            if(i>=0) val1=a[i]-'0';
            if (j>=0) val2=b[j]-'0';
            int ans=val1+val2+carry;
            s+=(ans%2) + '0';   
            carry=ans/2;
            i--;
            j--;
        }
        reverse(s.begin(), s.end());
        return s;
        
    }
};