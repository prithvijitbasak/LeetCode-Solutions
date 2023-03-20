//Editorial: https://leetcode.com/problems/can-place-flowers/editorial/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz=flowerbed.size();
        int cnt=0;
        for(int i=0;i<sz;i++)
        {
            if(flowerbed[i]==0)
            {
                // cout<<0<<" ";
                int leftempty=((i==0) or (flowerbed[i-1]==0));
                int rightempty=((i==sz-1) or (flowerbed[i+1]==0));
                if(leftempty and rightempty)
                {
                    flowerbed[i]=1;
                    cnt+=1;
                    if(cnt>=n)
                        return true;
                }
            }
        }
        return cnt>=n;
    }
};
