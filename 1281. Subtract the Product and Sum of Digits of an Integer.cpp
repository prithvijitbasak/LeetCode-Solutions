//Editorial: Very basic problem just a little knowledge of any language will be enough to solve this problem.
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sod=0,pod=1;
        int temp=n;
        while(temp>0)
        {
            sod+=temp%10;
            pod*=temp%10;
            temp/=10;
        }
        return (pod-sod);
    }
};
