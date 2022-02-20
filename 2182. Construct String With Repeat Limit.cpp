//Editorial: https://leetcode.com/problems/construct-string-with-repeat-limit/discuss/1784718/C%2B%2B-Greedy-%2B-Counting-O(N)-Time-O(1)-space
class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        string ans;
        vector<int> freq(26,0);
        for(char ch:s)
            freq[ch-'a']+=1;
        while(true)
        {
            int i=25;
            int ok=0;
            for(;i>=0;i--)
            {
                if(freq[i] and ans.size() and i==ans.back()-'a')
                {
                    ok=1;
                    continue;
                }
                if(freq[i])
                    break;
            }
            if(i<0)
                break;
            int fill=ok?1:min(freq[i],limit);
            freq[i]-=fill;
            while(fill--)
                ans+='a'+i;
        }
        return ans;
    }
};
