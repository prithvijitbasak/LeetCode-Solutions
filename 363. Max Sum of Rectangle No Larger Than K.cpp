// Editorial: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/1313721/JavaPython-Sub-problem:-Max-Sum-of-Subarray-No-Larger-Than-K-Clean-and-Concise
// Editorial for Maximum subarray sum less than or equals to k: https://www.geeksforgeeks.org/maximum-sum-subarray-having-sum-less-than-or-equal-to-given-sum-using-set/
class Solution {
public:
    int maxsum(vector<int> nums,int k)
    {
        set<int> st;
        st.insert(0);
        int n=nums.size(),csum=0;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            csum+=nums[i];
            auto it=st.lower_bound(csum-k);
            if(it!=st.end())
                ans=max(ans,csum-*it);
            st.insert(csum);
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            vector<int> sums(n,0);
            for(int j=i;j<m;j++)
            {
                for(int k=0;k<n;k++)
                    sums[k]+=matrix[j][k];
                ans=max(ans,maxsum(sums,k));
            }
        }
        return ans;
    }
};
