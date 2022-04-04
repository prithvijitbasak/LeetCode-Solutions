//Editorial: https://leetcode.com/problems/arranging-coins/solution/
class Solution {
public:
    int arrangeCoins(int n) {
        long long int low=1,high=n;
        while(low<=high)
        {
            long long int mid=low+(high-low)/2;
            long long int curr=mid*(mid+1)/2;
            if(curr==n)
                return mid;
            else if(curr<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};
