//Editorial: https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/60309/C%2B%2B-STL-partition-and-heapsort
//Approach 1: Using maxheap.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxh;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            maxh.push(nums[i]);
        }
        k-=1;
        while(k--)
        {
            maxh.pop();
        }
        return maxh.top();
    }
};
//Approach 2: Using minheap.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minh;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            minh.push(nums[i]);
            if(minh.size()>k)
                minh.pop();
        }
        return minh.top();
    }
};
