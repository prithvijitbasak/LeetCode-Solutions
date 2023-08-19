//Editorial: Easy and concise. TC: O(n^2log(n));
class Solution {
public:
    int func(int num) {
        int maxval=1;
        int temp=num;
        while(temp) {
            maxval=max(temp%10,maxval);
            temp/=10;
        }
        return maxval;
    }
    int maxSum(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i!=j) {
                    int f=nums[i];
                    int s=nums[j]; 
                    int maxi1=func(f);
                    int maxi2=func(s);
                    if(maxi1==maxi2) 
                        ans=max(ans,f+s);
                }
            }
        }
        return ans;
    }
};
