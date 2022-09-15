//Editorial: https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/2578114/Short-oror-C++-oror-Java-oror-PYTHON-oror-Explained-Solution-oror-Beginner-Friendly-oror-BY-MR-CODER
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        vector<int> ans;
        map<int,int> mp;
        for(auto it:changed)
            mp[it]+=1;
        if(n%2!=0)
            return ans;
        sort(changed.begin(),changed.end());
        for(int i=0;i<n;i++)
        {
            if(mp[changed[i]]==0)
                continue;
            if(mp[changed[i]*2]==0)
                return {};
            ans.push_back(changed[i]);
            mp[changed[i]]-=1;
            mp[changed[i]*2]-=1;
        }
        return ans;
    }
};
