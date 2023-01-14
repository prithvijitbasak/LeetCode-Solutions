//Editorial: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/2867563/lexicographically-smallest-equivalent-string/?orderBy=most_votes
class Solution {
public:
    vector<int> parent;
    int find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int a,int b)
    {
        int x=find(a);
        int y=find(b);
        if(x==y)
            return;
        if(x<y)
            parent[y]=x;
        else
            parent[x]=y;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26,0);
        for(int i=0;i<26;i++)
            parent[i]=i;
        int n=s1.size();
        for(int i=0;i<n;i++)
            Union(s1[i]-'a',s2[i]-'a');
        string ans="";
        for(int i=0;i<baseStr.size();i++)
            ans+=(char)(find(baseStr[i]-'a')+'a');
        return ans;
    }
};
