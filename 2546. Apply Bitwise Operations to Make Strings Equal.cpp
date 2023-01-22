//Editorial: https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/solutions/3083831/java-c-python-1-line-check-1/?orderBy=most_votes
class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s==target)
            return true;
        int val1=count(s.begin(),s.end(),'1');
        int val2=count(target.begin(),target.end(),'1');
        if(val1==0 or val2==0)
            return false;
        return true;
    }
};
