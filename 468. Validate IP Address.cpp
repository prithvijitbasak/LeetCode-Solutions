//Editorial: https://leetcode.com/problems/validate-ip-address/discuss/238511/C++-split
class Solution {
public:
    vector<string> split(string s,char ch)
    {
        vector<string> parts;
        string part;
        istringstream str(s);
        while(getline(str,part,ch))
            parts.push_back(part);
        return parts;
    }
    bool validIPv4(string s)
    {
        if(count(s.begin(),s.end(),'.')!=3)
             return false;
        vector<string> parts=split(s,'.');
        if(parts.size()!=4)
            return false;
        for(auto it:parts)
        {
            if(it.empty() or it.size()>3 or (it.size()>1 and it[0]=='0'))
                return false;
            for(char ch:it)
            {
                if(!isdigit(ch))
                    return false;
            }
            if(stoi(it)>255)
                return false;
        }
        return true;
    }
    bool validIPv6(string s)
    {
        if(count(s.begin(),s.end(),':')!=7)
            return false;
        vector<string> parts=split(s,':');
        if(parts.size()!=8)
            return false;
        for(auto it:parts)
        {
            if(it.empty() or it.size()>4)
                return false;
            for(auto ch:it)
            {
                if(!isxdigit(ch))
                    return false;
            }
        }
        return true;
    }
    string validIPAddress(string s) {
        if(validIPv4(s))
            return "IPv4";
        if(validIPv6(s))
            return "IPv6";
        return "Neither";
    }
};
