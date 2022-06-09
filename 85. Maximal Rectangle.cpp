//Editorial: https://youtu.be/St0Jf_VmG_g
class Solution {
public:
    int mah(vector<int> heights)
    {
        int n=heights.size();
        stack<int> stk;
        int area=0;
        for(int i=0;i<=n;i++)
        {
            while(!stk.empty() and (i==n or heights[stk.top()]>=heights[i]))
            {
                int h=heights[stk.top()];
                stk.pop();
                int w;
                if(stk.empty())
                    w=i;
                else
                    w=i-stk.top()-1;
                area=max(area,h*w);
            }
            stk.push(i);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> heights(n,0);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                    heights[j]+=1;
                else
                    heights[j]=0;
            }
            ans=max(ans,mah(heights));
        }
        
        return ans;
    }
};
