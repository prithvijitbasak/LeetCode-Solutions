//Editorial: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/discuss/624185/C++-sliding-window-easy-solution
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        vector<pair<int,int>> vals;
        for(int i=0;i<nums.size();i++)
        {
            for(int it:nums[i])
                vals.push_back({it,i});
        }
        sort(vals.begin(),vals.end());
        int i=0,k=0;
        unordered_map<int,int> ump;
        for(int j=0;j<vals.size();j++)
        {
            if(!ump[vals[j].second])
                k+=1;
            ump[vals[j].second]+=1;
            if(k==nums.size())
            {
                while(ump[vals[i].second]>1)
                {
                    ump[vals[i].second]-=1;
                    i+=1;
                }
                if(ans.empty() or ans[1]-ans[0]>vals[j].first-vals[i].first)
                    ans={vals[i].first,vals[j].first};
            }
        }
        return ans;
    }
};
