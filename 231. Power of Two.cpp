// Editorial: Check if its negative or equal to 0 then the answer is always going to be false. Else just check if n&(n-1) is 1 or not.
// If its 1 then its always going to be false else its true.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        if(n&(n-1))
            return false;
        return true;
    }
};
