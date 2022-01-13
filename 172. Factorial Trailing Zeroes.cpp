//Editorial: https://youtu.be/fx8rUY_iIms
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt=0;
        for(int i=5;n/i>=1;i*=5)
            cnt+=(n/i);
        return cnt;
    }
};
