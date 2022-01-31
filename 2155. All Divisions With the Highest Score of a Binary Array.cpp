//Editorial: https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/discuss/1730440/C%2B%2B-Prefix-Suffix-sum-or-Count-0's-and-1's-or-O(n)
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        int one=accumulate(arr.begin(),arr.end(),0);
        int zero=0;
        int mx=0;
        for(int i=0;i<=n;i++)
        {
            int curr=zero+one;
            if(curr>mx)
            {
                mx=curr;
                ans={i};
            }
            else if(mx==curr)
                ans.push_back(i);
            if(i!=n)
            {
                one-=arr[i]==1;
                zero+=arr[i]==0;
            }
        }
        return ans;
    }
};
