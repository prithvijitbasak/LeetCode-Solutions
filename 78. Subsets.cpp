//Editorial: https://youtu.be/b7AYbpM5YrE
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        int n=nums.size();
        for(int i=0;i<(1<<n);i++)
        {
            vector<int> ds;
            for(int bits=0;bits<n;bits++)
            {
                if(i&(1<<bits))
                    ds.push_back(nums[bits]);
            }
            ans.push_back(ds);
        }
        return ans;
    }
};
