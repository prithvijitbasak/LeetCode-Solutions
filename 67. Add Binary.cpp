//Editorial: https://leetcode.com/problems/add-binary/solutions/24475/short-code-by-c/?orderBy=most_votes
class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int m=a.size();
        int n=b.size();
        int i=m-1;
        int j=n-1;
        int carry=0;
        while(i>=0 or j>=0 or carry)
        {
            int val1=(i>=0 and a[i]=='1')?1:0;
            int val2=(j>=0 and b[j]=='1')?1:0;
            ans=(((val1+val2+carry)%2==0)?'0':'1')+ans;
            carry=(val1+val2+carry)/2;
            i--;
            j--;
        }
        return ans;
    }
};
