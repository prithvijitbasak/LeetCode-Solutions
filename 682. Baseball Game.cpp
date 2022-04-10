//Editorial: https://leetcode.com/problems/baseball-game/solution/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int score=0;
        vector<int> ans;
        int temp=0;
        for(auto it:ops)
        {
            if((it[0]>='0' and it[0]<='9') or it[0]=='-')
            {
                ans.push_back(std::stoi(it));
            }
            if(it=="C")
                ans.pop_back();
            if(it=="D")
            {
                int num=ans.back();
                ans.push_back(2*num);
            }
            if(it=="+")
            {
                int f=ans[ans.size()-1];
                int s=ans[ans.size()-2];
                ans.push_back(f+s);
            }
        }
        return accumulate(ans.begin(),ans.end(),0);
    }
};
