//Editorial: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/discuss/1747526/C++-oror-easy-solution-oror-0-ms/1253769
class Solution {
public:
    int minimumSum(int num) {
        string s=to_string(num);
       sort(s.begin(),s.end());
       return stoi(s.substr(0,1)+s.substr(2,1))+stoi(s.substr(1,1)+s.substr(3,1));
    }
};
