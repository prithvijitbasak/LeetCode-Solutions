//Editorial: https://leetcode.com/problems/russian-doll-envelopes/discuss/1134011/JS-Python-Java-C%2B%2B-or-Easy-LIS-Solution-w-Explanation
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return b[1]<a[1];
        else
            return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> seq;
        seq.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++)
        {
            if(envelopes[i][1]>seq.back())
                seq.push_back(envelopes[i][1]);
            else
            {
                int idx=lower_bound(seq.begin(),seq.end(),envelopes[i][1])-seq.begin();
                seq[idx]=envelopes[i][1];
            }
        }
        return seq.size();
    }
};
