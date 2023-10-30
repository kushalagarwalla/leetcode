class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s=m+n-1;//end of array
        m--;
        n--;
        while(m>=0 && n>=0)
        {
            if(nums1[m]>=nums2[n])
            {
                nums1[s]=nums1[m];
                m--;
            }
            else if(nums1[m]<nums2[n])
            {
                nums1[s]=nums2[n];
                n--;
            }
            s--;
        }
        while(m>=0)
        {
           nums1[s]=nums1[m];
            m--;
            s--;
        }
         while(n>=0)
        {
           nums1[s]=nums2[n];
            n--;
            s--;
        }
    }
};