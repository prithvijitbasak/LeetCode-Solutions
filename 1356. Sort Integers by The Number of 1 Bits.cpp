//Editorial: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/discuss/517017/C%2B%2B-in-place-sort%2B-popcount
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](const int &a,const int &b){
            int cnta=__builtin_popcount(a);
            int cntb=__builtin_popcount(b);
            return cnta==cntb?a<b:cnta<cntb;
        });
        return arr;
    }
};
