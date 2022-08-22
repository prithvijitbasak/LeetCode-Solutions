//Editorial: https://leetcode.com/problems/power-of-four/discuss/772428/C++-Three-Solution-or-Explain-or-Naive-orBit-Manipulation
class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n>1)
        {
            if(n%4)
                return false;
            n/=4;
        }
        return n==1;
    }
};
