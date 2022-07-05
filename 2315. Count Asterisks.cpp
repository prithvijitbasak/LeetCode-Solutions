//Editorial: Just traverse through the string and if the count of '|' is even just count the numbers of asterisks. TC: O(n) SC: O(1)
class Solution {
public:
    int countAsterisks(string s) {
        int ans=0;
        int n=s.size();
        int cntbar=0;
        int f=1;
        for(int i=0;i<n;i++)
        {
            if(cntbar%2==0 and s[i]=='*')
                ans+=1;
            if(s[i]=='|')
                cntbar+=1;
        }
        return ans;
    }
};
