//Editorial: Just store the binary in a array and iterate over the array to get the answer.
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd=0,even=0;
        int temp=n;
        vector<int> bin;
        while(temp)
        {
            int rem=temp%2;
            bin.push_back(rem);
            temp/=2;
        }
        // reverse(bin.begin(),bin.end());
        for(int i=bin.size()-1;i>=0;i--)
        {
            if(i%2==0)
                even+=(bin[i]==1);
            else
                odd+=(bin[i]==1);
        }
        return vector<int> {even,odd};
    }
};
