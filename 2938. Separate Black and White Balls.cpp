//Editorial: In the solution code 
class Solution {
public:
    typedef long long ll;
    long long minimumSteps(string s) {
        ll ans = 0;
        ll n = s.size();
        // we are just taking the index where the zero should get placed 
        // so we are just finding differnce among the current index where is 0 is now and where the 0 should be 
        // we dont care about where 1 are placed as after swapping the zero to their desired position the 1s will
        // eventually get to the end 
        ll zeroIdx = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                ans += (i - zeroIdx);
                zeroIdx += 1;
            }
        }
        return ans;
    }
};
