//Editorial: Just count the number of occurences of the characters and update the other array.
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int n=chars.size();
        int i=0;
        while(i<n)
        {
            int curr=0;
            char ch=chars[i];
            while(i<n and chars[i]==ch)
            {
                curr+=1;
                i+=1;
            }
            ans.push_back(ch);
            if(curr>1)
            {
                string num=to_string(curr);
                for(auto it:num)
                    ans.push_back(it);
            }
        }
        chars.clear();
        for(auto it:ans)
            chars.push_back(it);
        return ans.size();
    }
};
