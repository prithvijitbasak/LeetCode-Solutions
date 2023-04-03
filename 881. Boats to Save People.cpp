//Editorial: https://leetcode.com/problems/boats-to-save-people/solution/ , https://leetcode.com/problems/boats-to-save-people/solutions/1877945/java-c-a-very-easy-explanation-trust-me/?orderBy=most_votes
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j)
        {
            int sum=people[i]+people[j];
            if(sum<=limit)
            {
                ans+=1;
                i+=1;
                j-=1;
            }
            else
            {
                ans+=1;
                j-=1;
            }
        }
        return ans;
    }
};
