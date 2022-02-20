//Approach 1: Brute force.
//Editorial: Just go to the every indices and check whether the condition is getting satisfied or not.
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j] and i*j%k==0)
                    cnt+=1;
            }
        }
        return cnt;
    }
};
//Approach 2: 
