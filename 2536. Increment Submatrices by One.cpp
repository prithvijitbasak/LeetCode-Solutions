//Editorial: https://leetcode.com/problems/increment-submatrices-by-one/solutions/3052675/python3-sweep-line-range-addition-with-visualization-clean-concise/?orderBy=most_votes
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n,vector<int> (n,0));
        int qm=queries.size();
        for(int i=0;i<qm;i++)
        {
            int r1=queries[i][0],c1=queries[i][1],r2=queries[i][2],c2=queries[i][3];
            for(int j=r1;j<=r2;j++)
            {
                ans[j][c1]+=1;
                // putting -1 in the c2+1 column's cell so that when we will sweep i.e. summing up the values from left to right in that row  a +1 will get deducted from the summation.
                if(c2+1<n)
                    ans[j][c2+1]-=1;
            }
        }
        for(int r=0;r<n;r++)
        {
            for(int c=1;c<n;c++)
                ans[r][c]+=ans[r][c-1];
        }
        return ans;
    }
};
