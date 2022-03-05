//Editorial: Just check for substrings of size 1,2,4 and add the answer as the given instructions.
class Solution {
public:
    string interpret(string command) {
        string ans="";
        for(int i=0;i<command.size();)
        {
            string s=command.substr(i,1);
            if(s=="G")
            {
                ans+="G";
                i+=1;
                continue;
            }
            s=command.substr(i,2);
            if(s=="()")
            {
                ans+="o";
                i+=2;
                continue;
            }
            s=command.substr(i,4);
            if(s=="(al)")
            {
                ans+="al";
                i+=4;
            }
        }
        return ans;
    }
};
