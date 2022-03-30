//Approach 1: Using negation
//Editorial: https://leetcode.com/problems/find-the-duplicate-number/solution/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int duplicate;
        for(int i=0;i<n;i++)
        {
            int curr=abs(nums[i]);
            if(nums[curr]<0)
            {
                duplicate=curr;
                break;
            }
            nums[curr]*=-1;
        }
        for(auto &it:nums) //restoring the default array
            it=abs(it);
        return duplicate;
    }
};
//Approach 2: Using Hashing
//Editorial: https://leetcode.com/problems/find-the-duplicate-number/solution/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(nums[0]!=nums[nums[0]])
            swap(nums[0],nums[nums[0]]);
        return nums[0];
    }
};
