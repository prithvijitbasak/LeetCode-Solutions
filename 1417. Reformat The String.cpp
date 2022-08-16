//Editorial: https://leetcode.com/problems/reformat-the-string/discuss/592228/C++-SIMPLE-EASY-WITH-EXPLANATION
class Solution {
public:
    string reformat(string s) {
        // unordered_map<char,int> ump;
        vector<char> numvals;
        vector<char> charvals;
        int ac=0,nc=0;
        for(auto it:s)
        {
            if(isdigit(it))
            {
                nc+=1;
                numvals.push_back(it);
            }
            else
            {
                ac+=1;
                charvals.push_back(it);
            }
            // ump[it]+=1;
        }
        // cout<<ac<<" "<<nc<<"\n";
        if(abs(ac-nc)>1)
            return "";
        int i=0,j=0;
        string ans="";
        int m=numvals.size(),n=charvals.size();
        if(ac>nc)
        {
            ans+=charvals[j];
            j++;
            while(i<m and j<n)
            {
                ans+=numvals[i];
                ans+=charvals[j];
                i++;
                j++;
            }
        }
        else if(nc>ac)
        {
            ans+=numvals[i];
            i++;
            while(i<m and j<n)
            {
                ans+=charvals[j];
                ans+=numvals[i];
                i++;
                j++;
            }
        }
        else
        {
            while(i<m and j<n)
            {
                ans+=numvals[i];
                ans+=charvals[j];
                i++;
                j++;
            }
        }
        return ans;
    }
};
