//Editorial: https://leetcode.com/problems/binary-watch/discuss/88451/0ms-C++-Back-tracking-Solution-with-explanation
class Solution {
public:
    vector<int> hour={1,2,4,8};
    vector<int> minute={1,2,4,8,16,32};
    void solve(vector<string> &ans,pair<int,int> time,int val,int idx)
    {
        if(val==0)
        {
            ans.push_back(to_string(time.first)+(time.second<10?":0":":")+to_string(time.second));
            return;
        }
        for(int i=idx;i<hour.size()+minute.size();i++)
        {
            if(i<hour.size())
            {
                time.first+=hour[i];
                if(time.first<12)
                    solve(ans,time,val-1,i+1);
                time.first-=hour[i];
            }
            else
            {
                time.second+=minute[i-hour.size()];
                if(time.second<60)
                    solve(ans,time,val-1,i+1);
                time.second-=minute[i-hour.size()];
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        solve(ans,make_pair(0,0),turnedOn,0);
        return ans;
    }
};
