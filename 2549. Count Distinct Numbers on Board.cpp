//Approach 1: Brute-force using set.
class Solution {
public:
    int distinctIntegers(int n) {
        set<int> st;
        if(n==1)
            return 1;
        for(int i=n;i>=1;i--)
        {
            for(int j=2;j<=n;j++)
            {
                if(i%j==1)
                    st.insert(i);
            }
        }
        return st.size();
    }
};
//Approach 2: One-liner.
//Editorial: https://leetcode.com/problems/count-distinct-numbers-on-board/solutions/3111651/java-c-python-return-n-1/?orderBy=most_votes
class Solution {
public:
    int distinctIntegers(int n) {
        return max(1,n-1);
    }
};
