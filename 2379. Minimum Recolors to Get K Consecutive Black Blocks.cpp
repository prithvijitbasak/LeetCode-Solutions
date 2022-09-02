// Editorial: Just slide through the string of window size k and count the number of 'W' in the window, return the minimum number 
// of 'W' in the string.
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int i=0,j=k-1;
        int ans=n;
        while(j<n)
        {
            string s=blocks.substr(i,k);
            int cnt=count(s.begin(),s.end(),'W');
            ans=min(cnt,ans);
            i++;
            j++;
        }
        return ans;
    }
};
