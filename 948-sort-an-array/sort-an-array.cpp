class Solution {
public:
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && arr[largest]<arr[left])
            largest=left;
        if(right<n && arr[largest]<arr[right])
            largest=right;

        if(largest!=i)
        {
            swap(arr[largest],arr[i]);
            heapify(arr,n,largest);
        }
    }
    void heapSort(vector<int> &arr,int n)
    {
        for (int i = n-1; i>0; i--)
        {
            //step 1: swap 1st and last element
            swap(arr[0], arr[i]);
            //step 2: call max heapify on the reduced heap
            heapify(arr, i, 0);            
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(nums,n,i);
        }
        heapSort(nums,n);
        return nums;
    }
};