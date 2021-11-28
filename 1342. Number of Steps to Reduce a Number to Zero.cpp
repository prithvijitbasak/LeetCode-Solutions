//Editorial: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/1062161/C%2B%2B-or-Bit-Manipulation-or-5-Approaches-or-0ms-O(logn)-Beats-100
class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        while(num!=0)
        {
            if(num%2==0)
                num/=2;
            else
                num--;
            cnt++;
        }
     return cnt;   
    }
};
