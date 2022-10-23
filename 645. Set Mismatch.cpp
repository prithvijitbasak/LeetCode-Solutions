//Editorial: https://leetcode.com/problems/set-mismatch/solution/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> ump;
        vector<int> ans(2);
        for(auto it:nums)
            ump[it]+=1;
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            if(ump.find(i)!=ump.end() and ump[i]>1)
                ans[0]=i;
            if(ump.find(i)==ump.end())
                ans[1]=i;
        }
        return ans;
    }
};
