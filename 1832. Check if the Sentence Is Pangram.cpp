//Editorial: https://leetcode.com/problems/check-if-the-sentence-is-pangram/solution/
//Approach 1: Using set. TC: O(n) SC: O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for(auto it:sentence)
            st.insert(it);
        return st.size()==26;
    }
};
//Approach 2: Using bit manipulation. TC: O(n) SC: O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int seen=0;
        for(auto it:sentence)
        {
            int curr=it-'a';
            int val=1<<curr;
            seen|=val;
        }
        return seen==(1<<26)-1;
    }
};
