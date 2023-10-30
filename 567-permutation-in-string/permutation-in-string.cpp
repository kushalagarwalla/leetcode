class Solution {
public:
    bool checkEqual(int count1[],int count2[])
    {
        for(int i=0;i<26;i++)
        {
            if(count1[i]!=count2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        //Character Count array
        int count1[26]={0};
        for(int i=0;i<s1.length();i++)
        {
            int index=s1[i]-'a';
            count1[index]++;
        }
        //traverse the second array
        int i=0;
        int windowSize=s1.length();
        int count2[26]={0};
        //for first window
        while(i<windowSize && i<s2.length())//i<s2.length() is edge case
        {
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(checkEqual(count1,count2))
            return true;
        //for rest of the string
        while(i<s2.length())
        {
            int index=s2[i]-'a';
            count2[index]++;
            //delete count of old winodw
            char oldChar=s2[i-windowSize];
            index=oldChar-'a';
            count2[index]--;
            
            i++;

            if(checkEqual(count1,count2))
                return true;
        }
        return false;
    }
};