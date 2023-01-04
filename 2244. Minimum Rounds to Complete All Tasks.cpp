//Editorial: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/solutions/2779140/minimum-rounds-to-complete-all-tasks/?orderBy=most_votes
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> ump;
        for(auto it:tasks)
            ump[it]+=1;
        int ans=0;
        for(auto it:ump)
        {
            if(it.second == 1)
                return -1;
            if(it.second%3 == 0)
                ans+=(it.second/3);
            else
                ans+=(it.second/3)+1;
        }
        return ans;
    }
};
