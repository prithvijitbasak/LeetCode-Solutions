//Editorial: https://leetcode.com/problems/integer-to-english-words/solutions/3220257/c-recursion-easiest-beginner-friendly-sol/
class Solution {
public:
    vector<string> less20={""," One"," Two"," Three"," Four"," Five"," Six", " Seven"," Eight"," Nine"," Ten"," Eleven"," Twelve"," Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"};
    vector<string> tens={""," Ten"," Twenty"," Thirty"," Forty"," Fifty"," Sixty"," Seventy"," Eighty"," Ninety"};
    vector<string> thousand={""," Thousand"," Million"," Billion"};
    string helper(int val)
    {
        if(val<20)
            return less20[val];
        if(val<100)
            return tens[val/10]+helper(val%10);
        if(val<1000)
            return helper(val/100)+" Hundred"+helper(val%100);
        for(int i=3;i>=0;i--)
        {
            if(val>=(pow(1000,i)))
                return helper(val/pow(1000,i))+thousand[i]+helper(val%(int)(pow(1000,i)));
        }
        return "";
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        return helper(num).substr(1);
    }
};
