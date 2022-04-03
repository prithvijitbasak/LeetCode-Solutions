//Editorial: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/discuss/1908782/C%2B%2B-Greedy
class Solution {
public:
    int getTime(string s)
    {
        return stoi(s.substr(0,2))*60+stoi(s.substr(3));
    }
    int convertTime(string current, string correct) {
        int ans=0;
        int diff=getTime(correct)-getTime(current);
        vector<int> opt={60,15,5,1};
        for(auto it:opt)
        {
            ans+=(diff/it);
            diff%=it;
        }
        return ans;
    }
};
