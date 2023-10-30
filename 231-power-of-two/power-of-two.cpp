class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
        int count=0;
        while(n!=0)
        {
            int bit=n&1;
            if(bit==1)
            count++;
            n=n>>1;
        }
        if(count==1)
        return true;
        return false;
       /* int ans=1;
        for(int i=0;i<=30;i++)
        {   
            //ans=pow(2,i);
            if(ans==n)
                return true;
            if(ans<INT_MAX/2)
            ans=ans*2;
            
        }*/
    }
};