//Editorial: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/solutions/3230950/stepwise-explanation-with-images-easy-to-understand-simple-division-rule/?orderBy=most_votes
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        // here we are assigning the size as n and a previous remainder variable 
        long long int n = word.size(), prevRem = 0;
        // the answer vector 
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++)
        {
            int currDig = word[i] - '0';
            // we are adding the number to the previous remainder because in
            // division we divide the first digit by the divisor and then add the second digit to the 
            // reaminder of the divison of first digit by divisor 
            // we keep on doing this until the 
            // last digit comes
            // we are doing this because of if we just normally keep on adding the last value
            // to the variable I mean if just keep on dividing like this :-
            // imagine word = "123456789"
            // and m =3
            // and we do 
            // first divide by 1 then by 12 and then 123 and then 1234 this 
            // will lead to runtime error because the size of word might be 1e5 and there
            // is no any value in int or long long in to that can hold upto 1e5 digits therefore we need to apply
            // this trick
            long long int newDiv = (prevRem * 10) + currDig;
            if(newDiv % m == 0)
                ans[i] = 1;
            prevRem = (newDiv % m);
        }
        return ans;
    }
};
