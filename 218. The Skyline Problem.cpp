//Editorial: https://leetcode.com/problems/the-skyline-problem/discuss/61279/My-C++-code-using-one-priority-queue-(812-ms)
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        int n=buildings.size();
        int currx,currh=-1,curr=0;
        priority_queue<pair<int,int>> pq;
        while(curr<n or !pq.empty())
        {
            currx=(pq.empty())?buildings[curr][0]:pq.top().second;
            if(curr>=n or buildings[curr][0]>currx)
            {
                while(!pq.empty() and pq.top().second<=currx)
                    pq.pop();
            }
            else
            {
                currx=buildings[curr][0];
                while(curr<n and buildings[curr][0]==currx)
                {
                    pq.push({buildings[curr][2],buildings[curr][1]});
                    curr+=1;
                }
            }
            currh=(pq.empty())?0:pq.top().first;
            if(ans.empty() or ans.back()[1]!=currh)
                ans.push_back(vector<int> {currx,currh});
        }
        return ans;
    }
};
