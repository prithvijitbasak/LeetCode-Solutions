//Editorial: https://www.youtube.com/watch?v=ZOMKUPHcNRI&t=320s&ab_channel=ShivamPatel
class Solution {
public:
    int countDigitOne(int n) {
        if(n<=0)
            return 0;
        if(n<=9)
            return 1;
        unordered_map<int,int> mp;
        mp[9]=1;
        for(int i=9;i<(INT_MAX-9)/10;i=i*10+9)
            mp[i*10+9]=mp[i]*10+(i+1);
        int divisor=1;
        int temp=n;
        while(temp/10)
        {
            temp/=10;
            divisor*=10;
        }
        int fd=n/divisor;
        int rem=n%divisor;
        int ans=0;
        ans+=fd*mp[divisor-1];
        ans+=(fd>1)?divisor:0;
        ans+=(fd==1)?rem+1:0;
        ans+=countDigitOne(rem);
        return ans;
    }
};
