//Editorial: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/discuss/1231469/Simple-Solution-w-Explanation-or-Max-digit-or-1-Liners
class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(auto it:n)
            ans=max(ans,it-'0');
        return ans;
    }
};
