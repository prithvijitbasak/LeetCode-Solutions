//Editorial: https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/56729/Bit-operation-solution(JAVA)/58131
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i=0;
        while(left!=right)
        {
            left>>=1;
            right>>=1;
            i+=1;
        }
        return left<<i;
    }
};
