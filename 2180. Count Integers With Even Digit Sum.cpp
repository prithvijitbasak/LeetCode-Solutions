//Editorial: Just check if the sum of the numbers are even or not upto n.
class Solution {
public:
    int check(int n)
    {
        int sum=0;
        while(n!=0)
        {
            sum+=n%10;
            n/=10;
        }
        if(sum&1)
            return false;
        return true;
    }
    int countEven(int num) {
        int cnt=0;
        for(int i=1;i<=num;i++)
        {
            if(check(i))
                cnt+=1;
        }
        return cnt;
    }
};
