//Editorial: Just check whether the volume or mass is meeting up the conditions.
class Solution {
public:
    typedef long long ll;
    string categorizeBox(int l, int b, int h, int m) {
        ll vol=(ll)l*(ll)b*(ll)h;
        ll bulky=0,heavy=0;
        if(vol>=(ll)1e9 or l>=(ll)1e4 or b>=(ll)1e4 or h>=(ll)1e4 or m>=(ll)1e4)
            bulky=1;
        if(m>=(ll)100)
            heavy=1;
        if(bulky and heavy)
            return "Both";
        else if(bulky and !heavy)
            return "Bulky";
        else if(!bulky and heavy)
            return "Heavy";
        else
            return "Neither";
    }
};
