//Editorial: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/discuss/1783715/C%2B%2B-or-Easy-to-understand-or-Explained-with-example
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if(num%3!=0)
            return ans;
        else
        {
            long long mid=num/3;
            ans.push_back(mid-1);
            ans.push_back(mid);
            ans.push_back(mid+1);
            return ans;
        }
    }
};
