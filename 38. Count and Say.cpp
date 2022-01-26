//Editorial: https://leetcode.com/problems/count-and-say/discuss/16043/C%2B%2B-solution-easy-understand
class Solution {
public:
    string countAndSay(int n) {
        string ans="";
        ans="1";
        while(--n)
        {
            string curr="";
            for(int i=0;i<ans.size();i++)
            {
                int cnt=1;
                while(i+1<ans.size() and (ans[i]==ans[i+1]))
                {
                    cnt++;
                    i++;
                }
                curr+=to_string(cnt)+ans[i];
            }
            ans=curr;
        }
        
        return ans;
    }
};
