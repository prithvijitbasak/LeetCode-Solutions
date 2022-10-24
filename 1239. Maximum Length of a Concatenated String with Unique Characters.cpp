//Editorials: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/discuss/414806/C++-DFS-clean-and-concise-code.
class Solution {
public:
    int solve(vector<string> nums,string s,int index)
    {
        unordered_set<char> ust(s.begin(),s.end());
        if(s.size()!=ust.size())
            return 0;
        int ans=s.size();
        for(int i=index;i<nums.size();i++)
            ans=max(ans,solve(nums,s+nums[i],i+1));
        return ans;
    }
    int maxLength(vector<string>& arr) {
        int ans=solve(arr,"",0);
        return ans;
    }
};
