//Editorial: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/solution/
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need=(1<<k);
        int allone=need-1;
        int hashval=0;
        int n=s.size();
        vector<int> bits(need,0);
        for(int i=0;i<n;i++)
        {
            hashval=((hashval<<1)&allone)|(s[i]-'0');
            if(i>=k-1 and bits[hashval]==0)
            {
                bits[hashval]=1;
                need-=1;
                if(need==0)
                    return true;
            }
        }
        return false;
    }
};
