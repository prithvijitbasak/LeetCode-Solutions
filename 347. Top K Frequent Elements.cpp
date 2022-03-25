//Editorial: https://youtu.be/YPTqKIgVk-k
//Approach 1: Using minheap and hashing.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(auto it:nums)
            ump[it]+=1;
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(auto it=ump.begin();it!=ump.end();it++)
        {
            minh.push({it->second,it->first});
            if(minh.size()>k)
                minh.pop();
        }
        vector<int> ans;
        while(!minh.empty())
        {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};
//Approach 2: Using bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        for(auto it:nums)
            ump[it]+=1;
        int n=nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto it:ump)
            bucket[it.second].push_back(it.first);
        vector<int> ans;
        for(int i=n;i>=0 and ans.size()<k; i--)
        {
            for(auto it:bucket[i])
            {
                ans.push_back(it);
                if(ans.size()==k)
                    break;
            }
        }
        return ans;
    }
};
