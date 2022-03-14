//Editorial: https://leetcode.com/problems/simplify-path/discuss/25680/C%2B%2B-10-lines-solution, https://youtu.be/qYlHrAKJfyA
class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        vector<string> stack;
        string temp;
        stringstream s(path);
        while(getline(s,temp,'/'))
        {
            if(temp=="." or temp=="")
                continue;
            if(temp==".." and !stack.empty())
                stack.pop_back();
            else if(temp!="..")
                stack.push_back(temp);
        }
        for(auto it:stack)
            ans+=("/"+it);
        return (ans.empty())?"/":ans;
    }
};
