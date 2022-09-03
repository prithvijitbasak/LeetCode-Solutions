//Editorial: https://leetcode.com/problems/numbers-with-same-consecutive-differences/discuss/211183/JavaC++Python-Iterative-BFS-Solution
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans={1,2,3,4,5,6,7,8,9};
        for(int i=1;i<=n-1;i++)
        {
            vector<int> curr;
            for(auto it:ans)
            {
                int x=it%10;
                if(x+k<10)
                    curr.push_back((it*10)+x+k);
                if(k>0 and x-k>=0)
                    curr.push_back((it*10)+x-k);
            }
            ans=curr;
        }
        return ans;
    }
};
