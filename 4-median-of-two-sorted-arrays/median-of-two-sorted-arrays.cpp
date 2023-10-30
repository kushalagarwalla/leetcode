class Solution {
public:
    double findMedianOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int n1=nums1.size();
        int n2=nums2.size();
        int s=0, e=n1;
        while(s<=e)
        {
            int cut1=s+(e-s)/2;
            int cut2=((n1+n2)/2)-cut1;
            
            double l1=cut1==0?INT_MIN:nums1[cut1-1];
            double l2=cut2==0?INT_MIN:nums2[cut2-1];;
            double r1=cut1==n1?INT_MAX:nums1[cut1];
            double r2=cut2==n2?INT_MAX:nums2[cut2];
            
            if(l1>r2)
            {
              e=cut1-1;  
            }
            else if(l2>r1)
            {
                s=cut1+1;
            }
            else
            {
               ans= (n1+n2)%2==0?(max(l1,l2)+min(r1,r2))/2:min(r1,r2);
                break;
            }
            
        }
         
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size())
        {
            return findMedianOfTwoSortedArrays(nums1,nums2);
        }
        else
        {
            return findMedianOfTwoSortedArrays(nums2,nums1);
        }
        
    }
};