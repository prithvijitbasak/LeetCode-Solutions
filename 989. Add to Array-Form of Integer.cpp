Editorial: Just do the old school addition method to solve the problem. class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s=to_string(k);
        vector<int> valk;
        for(auto it:s)
            valk.push_back(it-'0');
        int m=num.size();
        int n=valk.size();
        int i=m-1;
        int j=n-1;
        int carry=0;
        string sum="";
        while(i>=0 or j>=0 or carry)
        {
            int value=0;
            if(i>=0)
            {
                value+=num[i];
                i-=1;
            }
            if(j>=0)
            {
                value+=valk[j];
                j-=1;
            }
            if(carry)
                value+=carry;
            char ch=(value%10)+'0';
            sum=ch+sum;
            carry=value/10;    
        }
        vector<int> ans;
        for(auto it:sum)
            ans.push_back(it-'0');
        return ans;
    }
};
