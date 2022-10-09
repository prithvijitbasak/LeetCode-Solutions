//Editorial: https://leetcode.com/problems/minimize-xor/discuss/2648779/Java-Intuition-behind-logic-or-Minimize-XOR
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        if(num1==num2)
            return num1;
        int cnt=__builtin_popcount(num2);
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int need=(num1>>i)&1;
            if(need and cnt>0)
            {
                ans|=(1<<i);
                cnt-=1;
            }
        }
        for(int i=0;i<32;i++)
        {
            if(!cnt)
                break;
            int need=(ans>>i)&1;
            if(!need)
            {
                ans|=(1<<i);
                cnt-=1;
            }
        }
        return ans;
    }
};
