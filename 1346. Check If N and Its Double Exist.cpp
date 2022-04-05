//Editorial: https://leetcode.com/problems/check-if-n-and-its-double-exist/discuss/1299922/C%2B%2B-3-solutions%3A-O(n.n)-greater-O(n.logn)-greater-O(n)
class Solution {
public:
    bool solve(vector<int> arr,int low,int high,int target)
    {
        if(low>high)
            return false;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==target)
                return true;
            else if(arr[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(arr[i]%2==0 and arr[i]<0)
            {
                if(solve(arr,i+1,n-1,arr[i]/2))
                    return true;
            }
            else
            {
                if(solve(arr,i+1,n-1,arr[i]*2))
                    return true;
            }
        }
        return false;
    }
};
