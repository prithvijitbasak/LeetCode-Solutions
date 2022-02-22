//Editorial: https://youtu.be/yDbkQd9t2ig
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int val1=-1,val2=-1;
        int cnt1=0,cnt2=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val1)
                cnt1+=1;
            else if(nums[i]==val2)
                cnt2+=1;
            else if(cnt1==0)
            {
                val1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                val2=nums[i];
                cnt2=1;
            }
            else
            {
                cnt1-=1;
                cnt2-=1;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val1)
                cnt1+=1;
            else if(nums[i]==val2)
                cnt2+=1;
        }
        vector<int> ans;
        if(cnt1>n/3)
            ans.push_back(val1);
        if(cnt2>n/3)
            ans.push_back(val2);
        return ans;
    }
};
