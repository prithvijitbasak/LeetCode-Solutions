//Editorial: https://youtu.be/M4dQNCp16Bw
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int gcd=__gcd(targetX,targetY);
        return (gcd&(gcd-1))==0;
    }
};
