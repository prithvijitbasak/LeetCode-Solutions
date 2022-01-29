//Method 1: TC: O(n)  SC:O(3n)
//Editorial: https://youtu.be/X0X6G-eWgQ8
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> stk;
        vector<int> pse(n),nge(n);
        for(int i=0;i<n;i++)
        {
            while(!stk.empty() and heights[stk.top()]>=heights[i])
                stk.pop();
            if(stk.empty())
                pse[i]=0;
            else
                pse[i]=stk.top()+1;
            stk.push(i);
        }
        while(!stk.empty())
            stk.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() and heights[stk.top()]>=heights[i])
                stk.pop();
            if(stk.empty())
                nge[i]=n-1;
            else
                nge[i]=stk.top()-1;
            stk.push(i);
        }
        int maxa=0;
        for(int i=0;i<n;i++)
        {
            maxa=max(maxa,heights[i]*(nge[i]-pse[i]+1));
        }
        return maxa;
    }
};
