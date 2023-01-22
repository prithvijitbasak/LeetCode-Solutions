//Editorial: If you don't know this kindly dive into the sun.
class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int sz=s.size();
        int ans=0;
        for(int i=0;i<sz;i++)
        {
            int val=(s[i]-'0');
            if(i%2==0)
                ans+=val;
            else
                ans+=-(val);
        }
        return ans;
    }
};
