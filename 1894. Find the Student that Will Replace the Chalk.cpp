//Editorial: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/discuss/1267332/C%2B%2BPython-Detailed-explanation-with-solution
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=accumulate(chalk.begin(),chalk.end(),0LL);
        k=k%sum;
        int n=chalk.size();
        for(int i=0;i<n;i++)
        {
            if(k-chalk[i]<0)
                return i;
            else
                k-=chalk[i];
        }
        return n-1;
    }
};
