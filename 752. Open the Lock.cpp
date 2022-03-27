//Editorial: https://leetcode.com/problems/open-the-lock/discuss/888436/C%2B%2B-Explained-With-Pictures-for-The-Ones-Who-Comes-Up-From-Behind
class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> ust(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        int ans = 0;
        string start="0000";
        if (ust.find(start) != ust.end()) {
            return -1;
        }
        queue<string> q;
        q.push(start);
        vis.insert(start);
        while (!q.empty()) {
            int len = q.size();
            while (len--) 
            {
                string up, down, currentWheel = q.front();
                q.pop();
                if (currentWheel == target) 
                    return ans;
                for (int i = 0; i < 4; i++) 
                {
                    down = up = currentWheel;
                    up[i] = (up[i] == '9' ? '0' : up[i] + 1);
                    down[i] = (down[i] == '0' ? '9' : down[i] - 1);
                    if (vis.find(up) == vis.end() && ust.find(up) == ust.end()) 
                    {
                        q.push(up);
                        vis.insert(up);
                    }
                    if (vis.find(down) == vis.end() && ust.find(down) == ust.end()) 
                    {
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            ans+=1;
        }
        return -1;
    }
};
