//Editorial: Just try to change the first 6 appearing from the left and if its not found then just return the initial number.
class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                return stoi(s);
            }
        }
        return stoi(s);
    }
};
