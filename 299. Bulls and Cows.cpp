//Editorial: (Self done) Go through the solution to get the idea.
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int n=secret.size();
        map<char,int> mps;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                st.insert(i);
                bulls+=1;
            }
            else
                mps[secret[i]]+=1;
        }
        int cows=0;
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end())
            {
                if(mps[guess[i]]>0)
                {
                    cows+=1;
                    mps[guess[i]]-=1;
                }
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
