//Editorial: Just map the values of one array and check the answer in the other.
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int ans=INT_MAX;
        map<int,int> mp;
        for(auto it:nums1)
            mp[it]+=1;
        for(auto it:nums2)
        {
            if(mp.find(it)!=mp.end())
                ans=min(ans,it);
        }
        return ans==INT_MAX?-1:ans;
    }
};
