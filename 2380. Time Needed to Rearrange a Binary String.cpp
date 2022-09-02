// Editorial: Just use brute-force technique to check whether there is any occurence of "01" in the string and if there is any just
// swap the values.
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans=0,n=s.size();
        int changed=1;
        while(changed)
        {
            changed=0;
            for(int i=0;i<n-1;i++)
            {
                if(s[i]=='0' and s[i+1]=='1')
                {
                    s[i]='1';
                    s[i+1]='0';
                    i++;
                    changed=1;
                }
            }
            ans+=changed;
        }
        return ans;
    }
};
