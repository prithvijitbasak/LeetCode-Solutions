//Editorial: Using a map to store the values.
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(auto it:nums1)
            mp[it[0]]+=it[1];
        for(auto it:nums2)
            mp[it[0]]+=it[1];
        for(auto it:mp)
            ans.push_back(vector<int> {it.first,it.second});
        return ans;
    }
};
