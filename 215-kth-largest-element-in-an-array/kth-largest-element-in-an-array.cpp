class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //step 1: Create a min-heap for first  k elements.
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        //step 2: for rest of the elements check if element > heap.top.
                    //If yes, then heap.pop and heap.push(element)
        for(int i=k;i<nums.size();i++)
        {
            if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        //step 3: return heap.top()
        return pq.top();
    }
};