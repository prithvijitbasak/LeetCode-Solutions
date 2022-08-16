//Editorial: Using priority_queue to  store the frequecy in decreasing order.
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> ump;
        for(auto it:s)
            ump[it]+=1;
        priority_queue<pair<int,char>> pq;
        string ans="";
        for(auto it:ump)
            pq.push({it.second,it.first});
        while(!pq.empty())
        {
            int cnt=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            while(cnt--)
                ans+=ch;
        }
        return ans;
    }
};
