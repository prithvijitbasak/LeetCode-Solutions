//Editorial: Just check for the uppercase letters and if we get any add 32 with it.
class Solution {
public:
    string toLowerCase(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' and s[i]<='Z')
                s[i]+=32;
        }
        return s;
    }
};
