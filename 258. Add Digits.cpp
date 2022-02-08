//Editorial: https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C%2B%2B-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations, https://en.wikipedia.org/wiki/Digital_root
class Solution {
public:
    int addDigits(int num) {
        int ans=num%9;
        if(ans!=0 or num==0)
            return ans;
        else
            return 9;
    }
};
