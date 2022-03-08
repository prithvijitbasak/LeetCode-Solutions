//Editorial: https://leetcode.com/problems/keys-and-rooms/solution/
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> stk;
        stk.push(0);
        int n=rooms.size();
        vector<int> vis(n,0);
        vis[0]=1;
        while(!stk.empty())
        {
            int node=stk.top();
            stk.pop();
            for(int it=0;it<rooms[node].size();it++)
            {
                if(!vis[rooms[node][it]])
                {
                    stk.push(rooms[node][it]);
                    vis[rooms[node][it]]=1;
                }
            }
        }
        for(auto it:vis)
        {
            if(it==0)
                return false;
        } 
        return true;
    }
};
