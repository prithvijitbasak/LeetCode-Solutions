//Editorial: https://leetcode.com/problems/k-similar-strings/discuss/151500/Logical-Thinking-with-Clear-Java-Code
class Solution {
public:
    vector<string> getneighbours(string a,string b)
    {
        vector<string> ans;
        int i=0;
        for(;i<a.size();i++)
        {
            if(a[i]!=b[i])
                break;
        }
        for(int j=i+1;j<b.size();j++)
        {
            if(a[j]==b[i])
            {
                swap(a[i],a[j]);
                ans.push_back(a);
                swap(a[i],a[j]);
            }
        }
        return ans;
    }
    int kSimilarity(string a, string b) {
        queue<string> q;
        set<string> st;
        st.insert(a);
        q.push(a);
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                string curr=q.front();
                q.pop();
                if(curr==b)
                    return level;
                for(auto it:getneighbours(curr,b))
                {
                    if(st.find(it)==st.end())
                    {
                        st.insert(it);
                        q.push(it);
                    }
                }
            }
            level+=1;
        }
        return -1;
    }
};
