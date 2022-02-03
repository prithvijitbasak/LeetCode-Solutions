//Editorial: https://leetcode.com/problems/4sum-ii/discuss/93925/Concise-C++-11-code-beat-99.5
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> ump;
        for(auto a:nums1)
        {
            for(auto b:nums2)
                ump[a+b]++;
        }
        int ans=0;
        for(auto c:nums3)
        {
            for(auto d:nums4)
            {
                auto it=ump.find(0-c-d);
                if(it!=ump.end())
                    ans+=it->second;
            }
        }
        return ans;
    }
};
