//Editorial: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/discuss/2612407/C++-or-Diagram-or-Related-Problems
//Approach 1: By finding the length of bits of each number. TC: O(nlogn) SC: O(1) 
class Solution {
public:
    int numOfBits(int n)
    {
        return log2(n)+1;
    }
    int concatenatedBinary(int n) {
        long long ans=0,mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            int len=numOfBits(i);
            ans=((ans<<len)%mod+i)%mod;
        }
        return ans;
    }
};
//Approach 2: Just by icreasing the len variable by 1 whenever we get the number of set bits as 1. TC: O(n) SC: O(1)
class Solution {
public:
    int concatenatedBinary(int n) {
        long long len=0,ans=0,mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            if(__builtin_popcount(i)==1)
                len+=1;
            ans=((ans<<len)%mod+i)%mod;
        }
        return ans;
    }
};
