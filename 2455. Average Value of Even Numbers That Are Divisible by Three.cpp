//Editorial: If you want editorial for this, then please go and dive in the SUN.
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0,cnt=0;
        for(auto it:nums)
        {
            if(it%3==0 and it%2==0)
            {
                cnt+=1;
                sum+=it;
            }
        }
        return cnt==0?0:(sum/cnt);
    }
};
