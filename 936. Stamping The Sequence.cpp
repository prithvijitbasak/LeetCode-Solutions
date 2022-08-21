//Editorial: https://youtu.be/EtalsGoNrBI
class Solution {
public:
    bool canReplace(string &target,int pos,string &stamp)
    {
        for(int i=0;i<stamp.size();i++)
        {
            if(target[i+pos]!='?' and target[i+pos]!=stamp[i])
                return false;
        }
        return true;
    }
    int replace(string &target,int pos,string &stamp,int &cnt)
    {
        for(int i=0;i<stamp.size();i++)
        {
            if(target[i+pos]!='?')
            {
                target[i+pos]='?';
                cnt+=1;
            }
        }
        return cnt;
    }
    vector<int> movesToStamp(string stamp, string target) {
        int tar=target.size();
        int n=stamp.size();
        int cnt=0;
        vector<int> vis(tar,0);
        vector<int> ans;
        while(cnt!=tar)
        {
            int f=0;
            for(int i=0;i<=tar-n;i++)
            {
                if(!vis[i] and canReplace(target,i,stamp))
                {
                    cnt=replace(target,i,stamp,cnt);
                    vis[i]=1;
                    f=1;
                    ans.push_back(i);
                    if(cnt==tar)
                        break;
                }
            }
            if(!f)
                return vector<int> {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
