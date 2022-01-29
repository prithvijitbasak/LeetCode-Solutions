//Editorial: https://youtu.be/Du881K7Jtk8
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);;
        stack<int> stk;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!stk.empty() and stk.top()<=nums[i%n])
                stk.pop();
            if(i<n)
            {
                if(!stk.empty())
                    nge[i]=stk.top();
            }
            stk.push(nums[i%n]);
        }
        return nge;
    }
};
