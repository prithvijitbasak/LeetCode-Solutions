//Editorial: https://leetcode.com/problems/array-of-doubled-pairs/discuss/203183/JavaC++Python-Match-from-the-Smallest-or-Biggest-100
class Solution {
public:
    static bool comp(int a,int b)
    {
        return abs(a)<abs(b);
    }
    bool canReorderDoubled(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums)
            mp[it]+=1;
        sort(nums.begin(),nums.end(),comp);
        for(auto it:nums)
        {
            if(mp[it]==0)
                continue;
            if(mp[it*2]==0)
                return false;
            mp[it]-=1;
            mp[it*2]-=1;
        }
        return true;
    }
};
