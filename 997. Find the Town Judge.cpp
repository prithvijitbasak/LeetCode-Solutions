//Editorial: https://leetcode.com/problems/find-the-town-judge/discuss/1663344/C%2B%2BJavaPython3Javascript-Everything-you-need-to-know-from-start-to-end-.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1,0);
        for(auto it:trust)
        {
            degree[it[0]]-=1;
            degree[it[1]]+=1;
        }
        for(int i=1;i<=n;i++)
        {
            if(degree[i]==n-1)
                return i;
        }
        return -1;
    }
};
