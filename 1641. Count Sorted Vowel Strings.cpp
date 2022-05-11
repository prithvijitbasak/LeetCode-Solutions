//Approach 1: Using dp. TC: O(n) SC: O(1)
//Editorial: https://leetcode.com/problems/count-sorted-vowel-strings/discuss/918507/Java-DP-O(n)-time-Easy-to-understand
class Solution {
public:
    int countVowelStrings(int n) {
        int a=1,e=1,i=1,o=1,u=1;
        while(n>1)
        {
            a+=(e+i+o+u); //putting a or e or i or o or u after a 
            e+=(i+o+u); // putting e or i or o or u after e
            i+=(o+u); // putting i or o or u after i
            o+=(u); // putting o or u after o
            u=(u); // putting u after u only
            n--;
        }
        return a+e+i+o+u;
    }
};
