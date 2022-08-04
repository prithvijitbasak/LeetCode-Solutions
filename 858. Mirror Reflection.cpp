//Editorial: https://youtu.be/_xIBOUWEq1c
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ext=q,ref=p;
        while(ext%2==0 and ref%2==0)
        {
            ext/=2;
            ref/=2;
        }
        if(ext&1 and ref&1)
            return 1;
        if(ext&1 and ref%2==0)
            return 2;
        if(ext%2==0 and ref&1)
            return 0;
        return -1;
    }
};
