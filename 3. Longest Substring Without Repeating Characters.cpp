//Editorial: https://youtu.be/qtVh-XEpsJo
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256,-1);
        int len=0,left=0,right=0,n=s.size();
        while(right<n)
        {
            if(mp[s[right]]!=-1)
                left=max(mp[s[right]]+1,left);
            mp[s[right]]=right;
            len=max(right-left+1,len);
            right++;
        }
        return len;
    }
};
