//Editorial: https://leetcode.com/problems/adding-spaces-to-a-string/discuss/1635042/C++-Two-Pointers
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int m=s.size();
        int n=spaces.size();
        int j=0;
        for(int i=0;i<m;i++)
        {
            if(j<n and i==spaces[j])
            {
                ans+=' ';
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};
