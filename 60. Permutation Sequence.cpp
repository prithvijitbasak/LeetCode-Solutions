//Editorial: https://youtu.be/wT7gcXLYoao
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        string ans="";
        vector<int> numbers;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            numbers.push_back(i);
        }
        k--;
        numbers.push_back(n);
        while(1)
        {
            ans+=to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0)
                break;
            k%=fact;
            fact/=numbers.size();
        }
        return ans;
    }
};
