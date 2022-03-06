// Editorial: Just keep on storing the frequency of next element after getting the key element and at the end return the element with max
// frequency in the map.
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int target;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==key)
                mp[nums[i+1]]+=1;
        }
        int mxcnt=0;
        for(auto it:mp)
        {
            if(it.second>=mxcnt)
            {
                mxcnt=it.second;
                target=it.first;
            }
        }
        return target;
    }
};
