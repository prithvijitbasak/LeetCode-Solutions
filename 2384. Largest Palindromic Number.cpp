//Editorial: https://leetcode.com/problems/largest-palindromic-number/discuss/2456626/CPP-JAVA-or-Greedy-or-O(n)-SPACE-or-O(N)-TIME
class Solution {
public:
    string largestPalindromic(string num) {
        int single=-1;
        int n=num.size();
        vector<int> freq(10);
        for(auto it:num)
            freq[it-'0']+=1;
        string res="";
        for(int i=9;i>=0;i--)
        {
            if(res.empty() and i==0)
                continue;
            while(freq[i]>1)
            {
                res+=(i+'0');
                freq[i]-=2;
            }
            if(freq[i]==1 and single==-1)
                single=i;
        }
        string ans=res;
        reverse(ans.begin(),ans.end());
        if(res.empty() and single==-1)
            return "0";
        if(single!=-1)
            res+=(single+'0');
        res+=ans;
        return res;
    }
};
