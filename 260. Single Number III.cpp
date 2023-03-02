//Editorial: https://www.youtube.com/live/ZwU6wSkepBI?feature=share
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val=0;
        for(auto it:nums)
            val^=it;
        int temp=val;
        int i=0;
        while(val)
        {
            if(val&1)
                break;
            i+=1;
            val>>=1;
        }
        int xor1=0,xor2=0;
        for(auto it:nums)
        {
            if(it&(1<<i))
                xor1^=it;
            else
                xor2^=it;
        }
        return vector<int> {xor1,xor2};
    }
};
