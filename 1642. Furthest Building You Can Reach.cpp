//Editorial: https://youtu.be/o84_EH4UJXc
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int totalbricksused=0;
        priority_queue<int> bricksused;
        int i=0;
        for(i;i<n-1;i++)
        {
            if(heights[i+1]<=heights[i])
                continue;
            int diff=heights[i+1]-heights[i];
            if(totalbricksused+diff<=bricks)
            {
                totalbricksused+=diff;
                bricksused.push(diff);
            }
            else if(ladders>0)
            {
                if(!bricksused.empty() and bricksused.top()>diff)
                {
                    totalbricksused-=bricksused.top()-diff;
                    bricksused.pop();
                    bricksused.push(diff);
                }
                ladders-=1;
            }
            else
                return i;
        }
        return n-1;
    }
};
