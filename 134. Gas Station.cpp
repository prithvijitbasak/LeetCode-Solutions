//Editorial: https://youtu.be/MWTHTDIBN0s , https://leetcode.com/problems/gas-station/solutions/1706142/java-c-python-an-explanation-that-ever-exists-till-now/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int totalsurplus=0,surplus=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            totalsurplus+=gas[i]-cost[i];
            surplus+=gas[i]-cost[i];
            if(surplus<0)
            {
                surplus=0;
                start=i+1;
            }
        }
        if(totalsurplus<0)
            return -1;
        return start;
    }
};
