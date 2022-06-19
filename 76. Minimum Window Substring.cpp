//Editorial: https://youtu.be/e1HlptlipB0
class Solution {
public:
    string minWindow(string s, string t) {
        int dmct=t.size();
        int mct=0;
        int n=s.size();
        int i=-1,j=-1;
        map<char,int> mp2,mp1;
        for(auto it:t)
            mp2[it]+=1;
        string ans="";
        while(1)
        {
            int f1=0,f2=0;
            while(i<n and mct<dmct)
            {
                i+=1;
                mp1[s[i]]+=1;
                if(mp1[s[i]]<=mp2[s[i]])
                    mct+=1;
                f1=1;
            }
            while(j<i and mct==dmct)
            {
                string pans=s.substr(j+1,i-j);
                if(ans.size()==0 or pans.size()<ans.size())
                    ans=pans;
                j+=1;
                if(mp1[s[j]]==1)
                    mp1[s[j]]=0;
                else
                    mp1[s[j]]-=1;
                if(mp1[s[j]]<mp2[s[j]])
                    mct-=1;
                f2=1;
            }
            if(!f1 and !f2)
                break;
        }
        return ans;
    }
};
