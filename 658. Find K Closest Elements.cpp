//Approach 1: Using two-pointer. TC: O(n-k) SC: O(1)
//Editorial: https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int low=0,high=n-1;
        while(high-low>=k)
        {
            if(x-arr[low]<=arr[high]-x)
                high--;
            else
                low++;
        }
        return vector<int>(arr.begin()+low,arr.begin()+high+1);
    }
};
//Approach 2: Using binary-search. TC: O(log(n-k)+k) SC: O(1)
//Editorial: https://youtu.be/o-YDQzHoaKM
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=size(arr);
        int low=0,high=n-k;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(x-arr[mid]>arr[mid+k]-x)
                low=mid+1;
            else
                high=mid;
        }
        return vector<int>(arr.begin()+low,arr.begin()+low+k);
    }
};
