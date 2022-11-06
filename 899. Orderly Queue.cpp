//Editorial: https://leetcode.com/problems/orderly-queue/discuss/165878/C++JavaPython-Sort-String-or-Rotate-String
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1)
        {
            sort(s.begin(),s.end());
            return s;
        }
        string ans=s;
        for(int i=1;i<s.size();i++)
        {
            string temp=s.substr(i)+s.substr(0,i);
            ans=min(ans,temp);
        }
        return ans;
    }
};
