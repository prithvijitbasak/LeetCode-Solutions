//Method 1: 2 pass solution
//Editorial: https://youtu.be/X0X6G-eWgQ8
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> stk;
        vector<int> pse(n),nse(n);
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
                nse[i]=n-1;
            else
                nse[i]=stk.top()-1;
            stk.push(i);
        }
        int maxa=0;
        for(int i=0;i<n;i++)
        {
            maxa=max(maxa,heights[i]*(nse[i]-pse[i]+1));
        }
        return maxa;
    }
};
//Approach 2: 1-pass solution.
//Editorial: https://youtu.be/jC_cWLy7jSI
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n=heights.size();
        int ans=0;
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
                ans=max(ans,h*w);
            }
            stk.push(i);
        }
        return ans;
    }
};
