//Editorial: https://leetcode.com/problems/magnetic-force-between-two-balls/discuss/794066/Simple-Explanation/658189
class Solution {
public:
    bool solve(vector<int> position,int mid,int m)
    {
        int prev=position[0],n=position.size();
        m--;
        int idx=1;
        while(idx<n and m>0)
        {
            if(position[idx]-prev>=mid)
            {
                m--;
                prev=position[idx];
            }
            idx+=1;
        }
        return m==0;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1];
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(solve(position,mid,m))
                low=mid+1;
            else
                high=mid;
        }
        return low-1;
    }
};
