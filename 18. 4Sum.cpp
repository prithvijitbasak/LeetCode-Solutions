//Editorial: https://youtu.be/4ggF3tXIAp0
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()==0)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int target2=target-nums[i]-nums[j];
                int low=j+1,high=nums.size()-1;
                while(low<high)
                {
                    int two_sum=nums[low]+nums[high];
                    if(target2==two_sum)
                    {
                        vector<int> temp(4);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[low];
                        temp[3]=nums[high];
                        ans.push_back(temp);
                        while(low<high and nums[low]==temp[2])
                            ++low;
                        while(low<high and nums[high]==temp[3])
                            --high;
                       // low++;
                       // high--;
                    }
                    else if(target2<two_sum)
                        high--;
                    else
                        low++;
                }
                while(j+1<nums.size() and nums[j+1]==nums[j])
                    j+=1;
            }
            while(i+1<nums.size() and nums[i+1]==nums[i])
                i+=1;
        }
        return ans;
    }
};
