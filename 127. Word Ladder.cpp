//Editorial: https://youtu.be/ZVJ3asMoZ18
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ust;
        int ok=0;
        for(auto word:wordList)
        {
            if(word.compare(endWord)==0)
                ok=1;
            ust.insert(word);
        }
        if(!ok)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty())
        {
            depth+=1;
            int level=q.size();
            while(level--)
            {
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.size();i++)
                {
                    string temp=curr;
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(curr.compare(temp)==0)
                            continue;
                        if(temp.compare(endWord)==0)
                            return depth+1;
                        if(ust.find(temp)!=ust.end())
                        {
                            q.push(temp);
                            ust.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
