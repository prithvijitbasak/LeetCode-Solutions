//Editorial: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/solutions/2889382/longest-path-with-different-adjacent-characters/?orderBy=most_votes
class Solution {
public:
    int dfs(int node,vector<int> adj[],string &s,long long int &ans)
    {
        int secondLongestChain=0,longestChain=0;
        for(auto child:adj[node])
        {
            int longestChainFromChild=dfs(child,adj,s,ans);
            if(s[node]==s[child])
                continue;
            if(longestChainFromChild>longestChain)
            {
                secondLongestChain=longestChain;
                longestChain=longestChainFromChild;
            }
            else if(longestChainFromChild>secondLongestChain)
                secondLongestChain=longestChainFromChild;
        }
        ans=max(ans,(long long int)longestChain+secondLongestChain+1);
        return longestChain+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<int> adj[n];
        for(int i=1;i<n;i++)
            adj[parent[i]].push_back(i);
        long long int ans=1;
        dfs(0,adj,s,ans);
        return ans;
    }
};
