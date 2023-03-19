//Editorial: https://www.youtube.com/watch?v=lEPYusrhihA&t=1284s&ab_channel=BroCoders
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> ump;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            val%=value;
            if(val<0)
                val+=value;
            ump[val]+=1;
        }
        int ans=0;
        int req=0;
        while(1)
        {
            if(ump[ans]==0)
                return ans;
            int cnt=ump[ans];
            int k=0;
            while(cnt--)
            {
                ump[ans+(k*value)]+=1;
                k+=1;
            }
            ans+=1;
        }
        return -1;
    }
};
