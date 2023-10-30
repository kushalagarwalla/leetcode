class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length())
        //find returns the first position of substring
        {
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};