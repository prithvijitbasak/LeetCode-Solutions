//Editorial: Just go through both the arrays and update the given values as required.
class Solution {
public:
    int minNumberOfHours(int ien, int iex, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        for(auto it:energy)
        {
            if(ien<=it)
            {
                ans+=abs(it-ien)+1;
                ien+=abs(it-ien)+1;
                ien-=it;
            }
            else
                ien-=it;
        }
        for(auto it:experience)
        {
            if(iex<=it)
            {
                ans+=abs(it-iex)+1;
                iex+=abs(it-iex)+1;
                iex+=it;
            }
            else
                iex+=it;
        }
        return ans;
    }
};
