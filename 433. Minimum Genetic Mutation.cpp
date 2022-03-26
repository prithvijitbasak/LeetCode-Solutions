//Editorial: Same as Word Ladder problem in LeetCode.
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> ust;
        int ok=0;
        for(auto it:bank)
        {
            ust.insert(it);
            if(it.compare(end)==0)
                ok=1;
        }
        if(!ok)
            return -1;
        queue<string> q;
        q.push(start);
        vector<char> store={'A','C','G','T'};
        int ans=1;
        while(!q.empty())
        {
            int len=q.size();
            ans+=1;
            while(len--)
            {
                auto node=q.front();
                q.pop();
                for(int i=0;i<node.size();i++)
                {
                    string temp=node;
                    for(int j=0;j<4;j++)
                    {
                        temp[i]=store[j];
                        if(temp.compare(end)==0)
                            return ans-1;
                        if(temp.compare(node)==0)
                            continue;
                        if(ust.find(temp)!=ust.end())
                        {
                            q.push(temp);
                            ust.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
