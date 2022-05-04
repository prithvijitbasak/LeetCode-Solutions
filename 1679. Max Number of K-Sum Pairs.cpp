//Editorial: https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/1023235/C++4-approaches-a-variation-of-two-sum
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> ump;
        int cnt=0;
        for(auto it:nums)
        {
            if(ump[k-it]>0)
            {
                cnt+=1;
                ump[k-it]-=1;
            }
            else
                ump[it]+=1;
        }
        return cnt;
    }
};
