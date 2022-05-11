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
//Approach 2: Using mathematics. TC: O(1) SC: O(1)
//Editorial: https://leetcode.com/problems/count-sorted-vowel-strings/discuss/1021493/One-line-solution-or-Math-or-No-DP-no-Big-Integers-or-O(1)-time-space
class Solution {
public:
    int countVowelStrings(int n) {
        return (n+1)*(n+2)*(n+3)*(n+4)/24;
    }
};
