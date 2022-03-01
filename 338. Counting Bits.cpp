//Editorial: https://youtu.be/awxaRgUB4Kw
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if(i&1)
                ans.push_back(ans[i/2]+1);
            else
                ans.push_back(ans[i/2]);
        }
        return ans;
    }
};
