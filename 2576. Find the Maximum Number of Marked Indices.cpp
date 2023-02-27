//Editorial: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/solutions/3230779/need-sorting-with-two-pointers-easy-way/?orderBy=most_votes
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j=n/2;
        int ans=0;
        while(i<n/2 and j<n)
        {
            if(2*nums[i]<=nums[j])
            {
                ans+=2;
                i+=1;
                j+=1;
            }
            else
                j+=1;
        }
        return ans;
    }
};
