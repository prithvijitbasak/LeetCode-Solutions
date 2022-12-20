//Approach 1: Using random fundction.
//Editorial: Just use rand() to get the random indexes. TC: O(n) SC: O(1)
class Solution {
public:
    vector<int> arr;
    Solution(vector<int>& nums) {
        arr=nums;
    }
    
    int pick(int target) {
        int n=arr.size();
        while(1)
        {
            int idx=rand()%n;
            if(arr[idx]==target)
                return idx;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
//Approach 2: Using hashmap. TC: O(1) SC: O(n)
class Solution {
public:
    unordered_map<int,vector<int>> ump;
    Solution(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
            ump[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return ump[target][rand()%ump[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
