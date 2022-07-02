//Editorial: https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/66331/C++-4ms-Recursive-and-DP-solution-with-brief-explanation
//Approach 1: Using recursion. TC: O(2^n) SC: O(n)
class Solution {
public:
    vector<int> ans;
    vector<int> solve(string s)
    {
        vector<int> res;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+' or s[i]=='-' or s[i]=='*')
            {
                vector<int> res1=solve(s.substr(0,i));
                vector<int> res2=solve(s.substr(i+1));
                for(auto it1:res1)
                {
                    for(auto it2:res2)
                    {
                        if(s[i]=='+')
                            res.push_back(it1+it2);
                        else if(s[i]=='-')
                            res.push_back(it1-it2);
                        else
                            res.push_back(it1*it2);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(atoi(s.c_str()));
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(s);
    }
};
//Approach 2: Using dp. TC: O(n^3) SC: O(n)
class Solution {
public:
    vector<int> solve(string s,unordered_map<string,vector<int>> &ump)
    {
        vector<int> res;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+' or s[i]=='-' or s[i]=='*')
            {
                vector<int> res1,res2;
                string temp=s.substr(0,i);
                if(ump.find(temp)!=ump.end())
                    res1=ump[temp];
                else
                    res1=solve(temp,ump);
                temp=s.substr(i+1);
                if(ump.find(temp)!=ump.end())
                    res2=ump[temp];
                else
                    res2=solve(temp,ump);
                for(auto it1:res1)
                {
                    for(auto it2:res2)
                    {
                        if(s[i]=='+')
                            res.push_back(it1+it2);
                        else if(s[i]=='-')
                            res.push_back(it1-it2);
                        else
                            res.push_back(it1*it2);
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(atoi(s.c_str()));
        ump[s]=res;
        return res;
    }
    vector<int> diffWaysToCompute(string s) {
        unordered_map<string,vector<int>> ump;
        return solve(s,ump);
    }
};
