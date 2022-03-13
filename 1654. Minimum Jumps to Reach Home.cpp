//Editorial: https://leetcode.com/problems/minimum-jumps-to-reach-home/discuss/950952/Fast-Python-and-C%2B%2B-solution-with-explanation-BFS
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> ust;
        for(auto it:forbidden)
            ust.insert(it);
        queue<pair<int,int>> q;
        q.push({0,1});
        int limit=2000+a+b;
        int ans=0;
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                auto it=q.front();
                q.pop();
                int val=it.first;
                int isforward=it.second;
                if(val==x)
                    return ans;
                if(ust.find(val)!=ust.end())
                    continue;
                ust.insert(val);
                if(isforward)
                {
                    int num=val-b;
                    if(num>=0)
                        q.push({num,0});
                }
                int num=val+a;
                if(num<=limit)
                    q.push({num,1});
            }
            ans+=1;
        }
        return -1;
    }
};
