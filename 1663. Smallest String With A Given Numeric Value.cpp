//Editorial: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/discuss/944411/C++-Simple-O(N)-with-explanation
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        k-=n;
        int i=n-1;
        while(k>0)
        {
            int temp=min(k,25);
            ans[i]+=temp;
            k-=temp;
            i--;
        }
        return ans;
    }
};
