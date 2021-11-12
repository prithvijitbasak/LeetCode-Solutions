//Editorial: https://leetcode.com/problems/multiply-strings/discuss/1563507/C%2B%2B-Simple-Easy-and-Short-Solution-Brief-Explanation
class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.size()+num2.size(),0);
        if(num1=="0" or num2=="0")
            return "0";
        for(int i=num1.size()-1;i>=0;i--)
        {
            for(int j=num2.size()-1;j>=0;j--)
            {
                ans[i+j+1]+=(num1[i]-'0')*(num2[j]-'0');
                ans[i+j]+=ans[i+j+1]/10;
                ans[i+j+1]%=10;
            }
        }
        int i=0;
        while(ans[i]==0)
            i++;
        string res="";
        for(;i<ans.size();i++)
            res+=to_string(ans[i]);
        return res;
    }
};
