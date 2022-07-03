//Editorial: https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/discuss/1931547/C++oror-0-ms-oror-O(nlogn)-oror-Easy-to-understand-oror-Commented-Explanation-oror-Priority-Queue
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> odd,even;
        string nums=to_string(num);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int vals=nums[i]-'0';
            if(vals&1)
                odd.push(vals);
            else
                even.push(vals);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int vals=nums[i]-'0';
            if(vals&1)
            {
                ans=(ans*10)+odd.top();
                odd.pop();
            }
            else
            {
                ans=(ans*10)+even.top();
                even.pop();
            }
        }
        return ans;
    }
};
