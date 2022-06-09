//Editorial: https://leetcode.com/problems/restore-ip-addresses/discuss/30972/WHO-CAN-BEAT-THIS-CODE
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string> ans;
        string res;
        for(int a=1;a<=3;a++)
        {
            for(int b=1;b<=3;b++)
            {
                for(int c=1;c<=3;c++)
                {
                    for(int d=1;d<=3;d++)
                    {
                        if(a+b+c+d==n)
                        {
                            int h1=stoi(s.substr(0,a));
                            int h2=stoi(s.substr(a,b));
                            int h3=stoi(s.substr(a+b,c));
                            int h4=stoi(s.substr(a+b+c,d));
                            if(h1<=255 and h2<=255 and h3<=255 and h4<=255)
                            {
                                if((res=to_string(h1)+'.'+to_string(h2)+'.'+to_string(h3)+'.'+to_string(h4)).size()==s.size()+3)
                                    ans.push_back(res);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
