//Editorial: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/discuss/1224643/Java-binary-search-explained/946665
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int low=1,high=1e7;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            double sum=0;
            for(int i=0;i<n-1;i++)
                sum+=ceil((double)(dist[i])/mid);
            sum+=(double)(dist[n-1])/mid;
            if(sum>hour)
                low=mid+1;
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};
