//Editorial: https://youtu.be/WBgsABoClE0
class Solution {
public:
    bool ispalin(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    void solve(int idx,string s,vector<string> &ds,vector<vector<string>> &ans)
    {
        if(idx==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<s.size();i++)
        {
            string temp=s.substr(idx,i-idx+1);
            if(ispalin(temp))
            {
                ds.push_back(temp);
                solve(i+1,s,ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0,s,ds,ans);
        return ans;
    }
};
