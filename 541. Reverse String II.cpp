//Editorial: https://leetcode.com/problems/reverse-string-ii/solutions/100887/c-java-clean-code/?orderBy=most_votes
class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.size();
        if(n<=k)
        {
            reverse(s.begin(),s.end());
            return s;
        }
        for(int i=0;i<n;)
        {
            if(i+k<n)
                reverse(s.begin()+i,s.begin()+i+k);
            else
                reverse(s.begin()+i,s.end());
            i+=2*k;
        }
        return s;
    }
};
