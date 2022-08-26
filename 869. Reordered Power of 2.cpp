//Editorial: https://leetcode.com/problems/reordered-power-of-2/solution/
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num=to_string(n);
        unordered_map<char,int> ump;
        for(auto it:num)
            ump[it]+=1;
        for(int i=0;i<31;i++)
        {
            unordered_map<char,int> temp;
            string s=to_string(1<<i);
            for(auto it:s)
                temp[it]+=1;
            if(temp==ump)
                return true;
        }
        return false;
    }
};
