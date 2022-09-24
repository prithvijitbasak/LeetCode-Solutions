//Editorial: It can be clearly understood that if the number if odd we got to return 2*n and if its even then its already a multiple of 2 so return that number itself.
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n&1)
            return 2*n;
        else
            return n;
    }
};
