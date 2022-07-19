//Editorial: https://youtu.be/uhgdXOlGYqE
//Approach 1: Using DP. TC: O(n^2) SC: O(n^2)
class Solution {
public:
    int dp[1005][1005];
    int f(int l, int r, vector <int> &piles) 
    {
        if(l == r-1) 
            return max(piles[l], piles[r]);
        if(dp[l][r] != -1) 
            return dp[l][r];    
        int ifleft = piles[l] + max(f(l+2, r, piles), f(l+1, r-1, piles));
        int ifright = piles[r] + max(f(l+1, r-1, piles), f(l, r-2, piles));
        
        return dp[l][r] = max(ifleft, ifright);
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        int alex = f(l, r, piles);
        int sum = 0;
        for(int i=0;i<piles.size();i++) 
            sum += piles[i];
        return alex > (sum - alex);
    }
};
//Approach 2: Using mathematics. TC: O(1) SC: O(1)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
