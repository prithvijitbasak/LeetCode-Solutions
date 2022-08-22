//Editorial: https://leetcode.com/problems/power-of-three/discuss/1178701/Power-Of-Three-or-Loops-Recursive-Direct-Approach-or-Multiple-Solutions-Explained-w-Clean-Code
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n>1)
        {
            if(n%3)
                return false;
            n/=3;
        }
        return n==1;
    }
};
