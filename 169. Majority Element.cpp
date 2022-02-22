//Editorial: https://youtu.be/AoX3BPWNnoE
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0,ans;
        for(auto it:nums)
        {
            if(cnt==0)
                ans=it;
            if(ans==it)
                cnt+=1;
            else
                cnt-=1;
        }
        return ans;
    }
};
