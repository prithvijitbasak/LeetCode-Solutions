//Editorial: https://leetcode.com/problems/find-the-closest-palindrome/solutions/649229/c-concise-and-easy-to-understand-with-explanation-faster-than-100/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    string nearestPalindromic(string n) {
        if(n.size()==1)
            return to_string(stoll(n)-1);
        ll ans;
        vector<ll> vals;
        ll digits=n.size();
        ll mid=(digits+1)/2;
        ll prefix=stoll(n.substr(0,mid));
        vals.push_back(pow(10,digits-1)-1);
        vals.push_back(pow(10,digits)+1);
        vector<ll> pres={prefix,prefix+1,prefix-1};
        for(auto it:pres)
        {
            string temp=to_string(it);
            if(digits%2!=0)
                temp.pop_back();
            reverse(temp.begin(),temp.end());
            string str=to_string(it)+temp;
            vals.push_back(stoll(str));
        }
        ll diff=INT_MAX;
        ll num=stoll(n);
        for(int i=0;i<5;i++)
        {
            if((num!=vals[i]) and abs(num-vals[i])<diff)
            {
                ans=(vals[i]);
                diff=abs(num-vals[i]);
            }
            else if(abs(num-vals[i])==diff)
                ans=(min(ans,vals[i]));
        }
        for(auto it:vals)
            cout<<it<<" ";
        return to_string(ans);
    }
};
