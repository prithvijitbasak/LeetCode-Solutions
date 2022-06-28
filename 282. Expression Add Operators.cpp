//Editorial: https://leetcode.com/problems/expression-add-operators/discuss/572099/C%2B%2BJavaPython-Backtracking-and-Evaluate-on-the-fly-Clean-and-Concise
class Solution {
public:
    vector<string> ans;
    string s;
    int target;
    vector<string> addOperators(string s, int target) {
        this->target=target;
        this->s=s;
        solve("",0,0,0);
        return ans;
    }
    void solve(string path,int pos,long long curr,long long prev)
    {
        if(pos==s.size() and curr==target)
        {
            ans.push_back(path);
            return;
        }
        string numstr="";
        long long num=0;
        for(int j=pos;j<s.size();j++)
        {
            if(j>pos and s[pos]=='0')
                break;
            numstr+=s[j];
            num=num*10+s[j]-'0';
            if(pos==0)
                solve(path+numstr,j+1,num,num);
            else
            {
                solve(path+'+'+numstr,j+1,curr+num,num);
                solve(path+'-'+numstr,j+1,curr-num,-num);
                solve(path+'*'+numstr,j+1,curr-prev+prev*num,prev*num);
            }
        }
    }
};
