//Editorial: https://youtu.be/3zyxpFPKkEU, https://leetcode.com/problems/utf-8-validation/discuss/87462/Concise-C++-implementation
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt=0;
        for(auto it:data)
        {
            if(cnt==0)
            {
                if(it>>5 == 0b110)
                    cnt=1;
                else if(it>>4 == 0b1110)
                    cnt=2;
                else if(it>>3 == 0b11110)
                    cnt=3;
                else if(it>>7)
                    return false;
            }
            else
            {
                if(it>>6 == 0b10)
                    cnt--;
                else
                    return false;
            }
        }
        return cnt==0;
    }
};
