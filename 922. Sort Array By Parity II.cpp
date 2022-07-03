//Editorial: Just simulate the input array to produce the answer
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd,even;
        for(auto it:nums)
        {
            if(it&1)
                odd.push_back(it);
            else
                even.push_back(it);
        }
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i&1)
            {
                nums[i]=odd.back();
                odd.pop_back();
            }
            else
            {
                nums[i]=even.back();
                even.pop_back();
            }
        }
        return nums;
    }
};
