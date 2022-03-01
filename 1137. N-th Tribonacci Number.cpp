//Approach 1: Using bottom-up dp with space optimisation. TC: O(n) SC: O(1)
////Editorial: https://leetcode.com/problems/n-th-tribonacci-number/discuss/345236/JavaC%2B%2BPython-Easy-and-Concise
class Solution {
public:
    int tribonacci(int n) {
        if(n<2)
            return n;
        if(n==2)
            return n-1;
        int a=0,b=1,c=1,d=0;
        for(int i=3;i<=n;i++)
        {
            d=a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return d;
    }
};
