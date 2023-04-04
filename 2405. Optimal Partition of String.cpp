//Editorial: Just keep iterating over the string if there is no any old character is found and if found then increase the answer.
class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;)
        {
            set<char> st;
            ans+=1;
            int f=0;
            while(i<n and st.find(s[i])==st.end())
            {
                f=1;
                st.insert(s[i]);
                i+=1;
            }
            if(!f)
                i+=1;
        }
        return ans;
    }
};
