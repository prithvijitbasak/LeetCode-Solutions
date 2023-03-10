//Editorial: https://youtu.be/WAOfKpxYHR8
class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& nums) {
        vector<int> adj[v];
        vector<int> indegree(v,0);
        for(int i=0;i<nums.size();i++)
            adj[nums[i][1]].push_back(nums[i][0]);
        for(int i=0;i<v;i++)
        {
            for(auto it:adj[i]) 
                indegree[it]+=1;
        }
        queue<int> q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]-=1;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(topo.size()!=v)
            topo.clear();
        //reverse(topo.begin(),topo.end());
        return topo;
    }
};
