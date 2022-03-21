//Editorial: https://leetcode.com/problems/partition-labels/solution/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int end=0,start=0;
        vector<int> freq(26,0);
        int n=s.size();
        for(int i=0;i<n;i++)
            freq[s[i]-'a']=i;
        for(int i=0;i<n;i++)
        {
            end=max(end,freq[s[i]-'a']);
            if(i==end)
            {
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};
