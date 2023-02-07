//Editorial: https://leetcode.com/problems/fruit-into-baskets/solutions/2960000/fruit-into-baskets/?orderBy=most_votes
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0,right=0,n=fruits.size();
        int ans=0;
        unordered_map<int,int> ump;
        for(right=0;right<n;right+=1)
        {
            ump[fruits[right]]+=1;
            if(ump.size()>2)
            {
                ump[fruits[left]]-=1;
                if(ump[fruits[left]]==0)
                    ump.erase(fruits[left]);
                left+=1;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
