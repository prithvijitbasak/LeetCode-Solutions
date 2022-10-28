//Editorial: https://leetcode.com/problems/image-overlap/discuss/2748237/C++-or-Hashmap-or-Fully-Explained-Intuition-or-Easy-Logic
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        vector<pair<int,int>> arr1,arr2;
        int n=img1.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]==1)
                    arr1.push_back({i,j});
                if(img2[i][j]==1)
                    arr2.push_back({i,j});
            }
        }
        map<pair<int,int>,int> mp;
        for(auto it1:arr1)
        {
            for(auto it2:arr2)
            {
                int a=(it1.first-it2.first);
                int b=(it1.second-it2.second);
                mp[{a,b}]+=1;
                ans=max(ans,mp[{a,b}]);
            }
        }
        return ans;
    }
};
