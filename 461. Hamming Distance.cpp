//Editorial: Just iterate of over the bits and take the xor(to check if that is different or not) if the xor value is 1 then its obviously different and increment the answer.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int val=1;
            int bit1=x&(val<<i);
            int bit2=y&(val<<i);
            if(bit1^bit2)
                ans+=1;
        }
        return ans;
    }
};
