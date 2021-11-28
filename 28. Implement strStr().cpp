// Editorial: This problem can be solved using KMP algorithm.
// To know about KMP algorithm watch: https://youtu.be/4jY57Ehc14Y
// But still if you have problem this.Then this is the perfect editorial: https://leetcode.com/problems/implement-strstr/discuss/12956/C%2B%2B-Brute-Force-and-KMP
class Solution {
public:
	int strStr(string haystack, string needle) {
        int n=needle.size();
        if(n==0)
        {
            return 0;
        }
		vector<int> lps(n);
        lpsarray(haystack,needle,lps);
        int i=0,j=0;
        int m=haystack.size();
        while(i<m)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            if(j==n)
                return i-j;
            if(haystack[i]!=needle[j] and i<m)
            {
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;
            }
        }
        return -1;
	}
    void lpsarray(string haystack,string needle,vector<int> &lps)
    {
        int len=0,i=1;
        int m=needle.size();
        lps[0]=0;
        while(i<m)
        {
            if(needle[i]==needle[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else if(len)
                len=lps[len-1];
            else
                lps[i++]=0;
        }
    }
};
