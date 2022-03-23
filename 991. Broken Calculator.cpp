//Editorial: https://leetcode.com/problems/broken-calculator/solution/
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(startValue<target)
        {
            ans+=1;
            if(target&1)
                target+=1;
            else
                target/=2;
        }
        return ans+startValue-target;
    }
};
