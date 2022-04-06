//Editorial: https://leetcode.com/problems/3sum-with-multiplicity/solution/
class Solution {
public:
    int threeSumMulti(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long ans=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            int newt=target-nums[i];
            int j=i+1,k=n-1;
            while(j<k)
            {
                //if the sum of the nums[j]+nums[k] is less than target-nums[i]
                if(nums[j]+nums[k]<newt)
                    j+=1;
                //if the sum of the nums[j]+nums[k] is more than target-nums[i]
                else if(nums[j]+nums[k]>newt)
                    k-=1;
                //if the sum becomes equal to the target-nums[i] but we have nums[j]==nums[j+1] or nums[k]==nums[k-1]
                else if(nums[j]!=nums[k])
                {
                    int left=1,right=1;
                    while(j+1<k and nums[j]==nums[j+1])
                    {
                        left+=1;
                        j+=1;
                    }
                    while(k-1>j and nums[k]==nums[k-1])
                    {
                        right+=1;
                        k-=1;
                    }
                    ans+=(left*right);
                    ans%=mod;
                    j++;
                    k--;
                }
                // if the sum is equal to the target-nums[i] but we have nums[j]==nums[k] the we need to find the number of integers having nums[j]==nums[k] and then find the lenC2 because there will be lenC2 numbers of pairs to obtain target-nums[i]  ......(nC2 can also be simplified to n*(n-1)/2)
                else
                {
                    int len=k-j+1;
                    ans+=(len*(len-1)/2);
                    ans%=mod;
                    break;
                }
            }
        }
        return (int)ans;
    }
};
