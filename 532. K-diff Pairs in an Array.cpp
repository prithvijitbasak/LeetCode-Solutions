//Editorial: https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/100101/C%2B%2B-O(N)-Time-with-unordered_map
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(auto it:nums)
            ump[it]++;
        int cnt=0;
        for(auto it:ump)
        {
            if((!k and it.second>1) or (k and ump.find(it.first+k)!=ump.end()))
               cnt++;
        }
        return cnt;
    }
};
