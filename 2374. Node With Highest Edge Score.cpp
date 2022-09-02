//Editorial: Just add the values of node having directed edge towards the node in that node and find the maximum among them.
class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long int ans,maxi=INT_MIN,n=edges.size();
        vector<long long int> edgesum(n,0);
        for(int i=0;i<edges.size();i++)
            edgesum[edges[i]]+=i;
        for(int i=0;i<n;i++)
        {
            if(edgesum[i]>maxi)
            {
                maxi=edgesum[i];
                ans=i;
            }
        }
        return ans;
    }
};
