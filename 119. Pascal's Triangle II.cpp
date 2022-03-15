//Editorial: https://leetcode.com/problems/pascals-triangle-ii/discuss/38420/Here-is-my-brief-O(k)-solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n=rowIndex;
        vector<int> ans(n+1,0);
        ans[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j>=1;j--)
                ans[j]+=ans[j-1];
        }
        return ans;
    }
};
