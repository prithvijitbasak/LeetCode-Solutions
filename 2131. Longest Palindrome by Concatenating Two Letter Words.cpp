//Editorial: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/discuss/1675343/Python3-Java-C++-Counting-Mirror-Words-O(n)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> ump;
        int unpaired=0,ans=0;
        for(auto it:words)
        {
            if(it[0]==it[1])
            {
                if(ump[it]>0)
                {
                    ans+=4;
                    unpaired-=1;
                    ump[it]-=1;
                }
                else
                {
                    ump[it]+=1;
                    unpaired+=1;
                }
            }
            else
            {
                string rev=it;
                reverse(rev.begin(),rev.end());
                if(ump[rev]>0)
                {
                    ans+=4;
                    ump[rev]-=1;
                }
                else
                    ump[it]+=1;
            }
        }
        if(unpaired>0)
            ans+=2;
        return ans;
    }
};
