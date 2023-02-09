//Editorial: https://leetcode.com/problems/naming-a-company/solutions/3081799/naming-a-company/
class Solution {
public:
    typedef long long ll;
    long long distinctNames(vector<string>& ideas) {
        ll ans=0;
        unordered_set<string> ust[26];
        int n=ideas.size();
        for(int i=0;i<n;i++)
            ust[ideas[i][0]-'a'].insert(ideas[i].substr(1));
        for(int i=0;i<25;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                int mutual=0;
                for(auto it:ust[j])
                {
                    if(ust[i].find(it)!=ust[i].end())
                        mutual+=1;
                }
                ans+=2*(ust[i].size()-mutual)*(ust[j].size()-mutual);
            }
        }
        return ans;
    }
};
