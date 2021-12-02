//Editorial: https://youtu.be/VyHEglhbm-A
class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string a, string b) {
        mp.clear();
    if(a.size()!=b.size())
      return 0;
    return solve(a,b);
        
    }
    bool solve(string a,string b)
{
    string key=a+" "+b;
    if(mp.find(key)!=mp.end())
      return mp[key];
    if(a.compare(b)==0)
      return mp[key]=1;
    if(a.size()<=1)
      return mp[key]=0;
    int flag=0;
    int n=a.size();
    for(int i=1;i<n;i++)
    {
if((solve(a.substr(0,i),b.substr(n-i,i)) and solve(a.substr(i),b.substr(0,n-i))) or (solve(a.substr(0,i),b.substr(0,i)) and solve(a.substr(i),b.substr(i))))
        {
          flag=1;
          break;
        }
    }
    return mp[key]=flag;
}

};
