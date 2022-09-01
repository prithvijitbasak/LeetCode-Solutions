//Editorial: https://youtu.be/X9v68RR2X0w
class Solution {
public:
    vector<int> kahn(vector<vector<int>> conditions,int k)
    {
        vector<int> ans;
        vector<int> graph[k+1];
        vector<int> indegree(k+1,0);
        for(int i=0;i<conditions.size();i++)
        {
            graph[conditions[i][0]].push_back(conditions[i][1]);
            indegree[conditions[i][1]]+=1;
        }
        queue<int> q;
        for(int i=1;i<k;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:graph[node])
            {
                indegree[it]-=1;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row_order=kahn(rowConditions,k+1);
        vector<int> col_order=kahn(colConditions,k+1);
        vector<vector<int>> ans(k,vector<int> (k,0));
        if(row_order.size()<k or col_order.size()<k)
            return {};
        unordered_map<int,int> ump;
        for(int i=0;i<k;i++)
            ump[col_order[i]]=i;
        for(int i=0;i<k;i++)
        {
            int col_pos=ump[row_order[i]];
            ans[i][col_pos]=row_order[i];
        }
        return ans;
    }
};
