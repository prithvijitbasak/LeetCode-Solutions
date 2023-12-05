//Editorial: https://leetcode.com/problems/count-complete-substrings/solutions/4355843/easy-explanation-c-sliding-window/
class Solution {
public:
    bool check(vector<int> &freq, int &ch, int &k)
    {
        int ct = 0;
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i] == 0)
                continue;
            if(freq[i] != k)
                return false;
            else
                ct += 1;
        }
        if(ct > ch)
            return false;
        return true;
    }
    long int func(string &res, int &k)
    {
        long long int cnt = 0;
        int n = res.size();
        for(int ch=1;ch<=26;ch++)
        {
            int len = ch*k;
            if(len > n)
                break;
            vector<int> freq(26, 0);
            for(int i=0;i<len;i++)
                freq[res[i] - 'a'] += 1;
            if(check(freq, ch, k))
                cnt += 1;
            for(int i=len;i<n;i++)
            {
                char prev = res[i-len];
                char next = res[i];
                freq[prev - 'a'] -= 1;
                freq[next - 'a'] += 1;
                if(check(freq, ch, k))
                    cnt += 1;
            }
        }
        return cnt;
    }
    int countCompleteSubstrings(string word, int k) {
        int ans = 0;
        int n = word.size();
        string res = "";
        for(int i=0;i<n;i++)
        {
            res += word[i];
            if(i < n-1)
            {
                if(abs(word[i] - word[i+1]) > 2)
                {
                    ans += func(res, k);
                    res = "";
                }
            }
        }
        ans += func(res, k);
        return ans;
    }
};
