class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        s.push(-1);
        unordered_map<int, int> nums1Map;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> ans(n1);
        vector<int> v(n2);

        for(int i=n2-1;i>=0;i--)
        {
            int val=nums2[i];
            while(s.top()!=-1 && s.top()<val)
            {
                s.pop();
            }
            v[i]=s.top();
            nums1Map[val]=v[i];
            s.push(val);
        }
        for(int i=0;i<n1;i++)
        {
            ans[i]=nums1Map[nums1[i]];
        }
        return ans;
    }
};