//Editorial: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/discuss/854184/JavaC%2B%2BPython-O(N)-Time-O(1)-Space
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int val=((i+1)*(n-i)+1)/2*arr[i];
            ans+=val;
        }
        return ans;
    }
};
