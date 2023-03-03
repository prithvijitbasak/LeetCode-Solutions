//Editorial: https://leetcode.com/problems/repeated-dna-sequences/solutions/898924/c-simple-and-short-solution-using-hashmap/?orderBy=most_votes
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string,int> mp;
        int n=s.size();
        for(int i=0;i+9<n;i++)
            mp[s.substr(i,10)]+=1;
        for(auto it:mp)
        {
            // cout<<it.first<<" "<<it.second<<"\n";
            if(it.second>1)
                ans.push_back(it.first);
        }
        return ans;
    }
};
