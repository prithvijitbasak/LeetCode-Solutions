//Editorial: https://leetcode.com/problems/alphabet-board-path/solutions/347835/c-short-and-clean-code-beat-100/?orderBy=most_votes
class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans="";
        map<char,pair<int,int>> mp;
        for(int i=0;i<26;i++)
            mp[i+'a']={i/5,i%5};
        int dx=0,dy=0;
        target='a'+target;
        int n=target.size();
        for(int i=1;i<n;i++)
        {
            dx=mp[target[i]].first-mp[target[i-1]].first;
            dy=mp[target[i]].second-mp[target[i-1]].second;
            if(dx<0)
                ans+=string(-dx,'U');
            if(dy<0)
                ans+=string(-dy,'L');
            if(dx>0)
                ans+=string(dx,'D');
            if(dy>0)
                ans+=string(dy,'R');
            ans+='!';
        }
        return ans;
    }
};
