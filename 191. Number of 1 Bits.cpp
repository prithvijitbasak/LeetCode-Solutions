//Approach 1: Using STL functions.(__builin_popcount() method).
class Solution {
public:
    int hammingWeight(uint32_t n) {
      return __builtin_popcount(n);
    }
};
//Approach 2: Brute force technique.
//Editorial: Going to every bit and check whether its set or not.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
                ans+=1;
        }
        return ans;
    }
};
