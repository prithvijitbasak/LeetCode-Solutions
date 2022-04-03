//Editorial: Just try to check if the mid of the range is equal to the given number or not. Go through the solution to get more clarity.
class Solution {
public:
    bool isPerfectSquare(int n) {
        long long int low=1,high=n;
        while(low<=high)
        {
            long long int mid=(low+high)>>1;
            if(mid*mid==n)
                return true;
            else if(mid*mid<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};
