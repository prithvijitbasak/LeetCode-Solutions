//Editorial: https://leetcode.com/problems/count-good-meals/discuss/999249/Easy-C++-Count-Good-Meals
class Solution {
public:
    int countPairs(vector<int>& nums) {
        unordered_map<int,int> ump;
        long long ans=0;
        for(auto it:nums)
        {
            for(int i=1;i<=(1<<22);i*=2)
            {
                if(ump.count(i-it))
                    ans+=ump[i-it];
            }
            ump[it]+=1;
        }
        return ans%(int)(1e9+7);
    }
};
