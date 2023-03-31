//Editorial: https://youtu.be/VyHEglhbm-A
class Solution {
public:
    unordered_map<string,int> ump;
    bool solve(string a,string b)
    {
        string key=a+" "+b;
        if(ump.find(key)!=ump.end())
            return ump[key];
        if(a.compare(b)==0)
            return ump[key]=1;
        if(a.size()<1)
            return ump[key]=0;
        int n=a.size();
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if((solve(a.substr(0,i),b.substr(n-i)) and solve(a.substr(i),b.substr(0,n-i))) or (solve(a.substr(0,i),b.substr(0,i)) and solve(a.substr(i),b.substr(i))))
            {
                flag=1;
                break;
            }
        }
        return ump[key]=flag;
    }
    bool isScramble(string a, string b) {
        if(a.size()!=b.size())
            return false;
        return solve(a,b);
    }
};
