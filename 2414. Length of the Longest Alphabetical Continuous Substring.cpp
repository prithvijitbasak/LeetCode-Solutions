//Editorial: Just increase the counter as long as the diffrerence between the two characters is 1.
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int ans=1;
        for(int i=1;i<n;i++)
        {
            int len=1;
            while(s[i]-s[i-1]==1 and i<n)
            {
                len+=1;
                ans=max(len,ans);
                i+=1;
            }
        }
        return ans;
    }
};
