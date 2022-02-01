//Editorial: https://youtu.be/l0YC3876qxg
class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long int n1=n;
        if(n1<0)
            n1=-1*n1;
        while(n1)
        {
            if(n1%2)
            {
                ans*=x;
                n1=n1-1;
            }
            else
            {
                x=x*x;
                n1/=2;
            }
        }
        if(n<0)
            ans=(double)(1.0)/(double)(ans);
        return ans;
    }
};
