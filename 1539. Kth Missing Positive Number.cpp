//Approach 1: Using linear search technique. TC: O(n) SC: O(1)
//Editorial: https://leetcode.com/problems/kth-missing-positive-number/discuss/1004517/C%2B%2B-2-LINER-SIMPLEST!!-O(n)-time-O(1)-space-faster-than-99
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(auto it:arr)
        {
            if(it<=k)
                k+=1;
        }
        return k;
    }
};
//Approach 2: Using Binary search. TC: O(logn) SC: O(1)
//Editorial: https://leetcode.com/problems/kth-missing-positive-number/discuss/1004437/C%2B%2B-Optimized-Solution-with-Detailed-Explanation-C%2B%2B-100Faster-0-ms
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]-(mid+1)<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low+k;
    }
};
