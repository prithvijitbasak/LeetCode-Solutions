//Editorial: https://youtu.be/UcoN6UjAI64
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            ans=(ans<<1)+((n>>i)&1);
        }
        return ans;
    }
};
