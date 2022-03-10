//Editorial: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/820072/EASY-soultion-with-DRY-RUN-JAVA
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos=0,neg=0,ans=0;
        for(auto it:nums)
        {
            if(it==0)
            {
                pos=0;
                neg=0;
            }
            else if(it>0)
            {
                pos+=1;
                neg=(neg==0)?0:neg+1;
            }
            else
            {
                int temp=pos;
                pos=(neg==0)?0:neg+1;
                neg=temp+1;
            }
            ans=max(ans,pos);
        }
        return ans;
    }
};
