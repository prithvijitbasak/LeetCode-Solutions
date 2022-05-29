//Editorial: https://leetcode.com/problems/maximum-product-of-word-lengths/discuss/1233648/Short-and-Easy-Solution-w-Explanation-or-C++-using-Bitset-and-Bit-masking-or-Beats-100
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> mask(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(auto it:words[i])
                mask[i]|=(1<<(it-'a'));
            for(int j=0;j<i;j++)
            {
                if((mask[i] & mask[j])==0)
                    ans=max(ans,int(size(words[i])*size(words[j])));
            }
        }
        return ans;
    }
};
