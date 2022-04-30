//Editorial: https://leetcode.com/problems/evaluate-division/discuss/1968813/C++-or-DFS-Solution-or-0-ms-or100
class Solution {
public:
    map<string,vector<string>> graph;
    map<string,double> mp;
    vector<double> ans;
    void dfs(int &f,map<string,int> &vis,string start,string end,double &val)
    {
        vis[start]=1;
        if(f==1)
            return;
        for(auto it:graph[start])
        {
            if(vis[it]!=1)
            {
                val*=mp[start+"->"+it];
                if(end==it)
                {
                    f=1;
                    return;
                }
                dfs(f,vis,it,end,val);
                if(f)
                    return;
                else
                    val/=mp[start+"->"+it];
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        for(int i=0;i<n;i++)
        {
            string start=equations[i][0];
            string end=equations[i][1];
            mp[start+"->"+end]=values[i];
            mp[end+"->"+start]=1/values[i];
            graph[start].push_back(end);
            graph[end].push_back(start);
        }
        for(int i=0;i<queries.size();i++)
        {
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end() or graph.find(end)==graph.end())
                ans.push_back(-1);
            else
            {
                double val=1;
                map<string,int> vis;
                int f=0;
                if(start==end)
                    f=1;
                else
                    dfs(f,vis,start,end,val);
                if(f)
                    ans.push_back(val);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
