//Editorial: https://leetcode.com/problems/compare-version-numbers/discuss/50804/10-line-concise-solution.-(C%2B%2B)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream s1(version1);
        istringstream s2(version2);
        int num1=0,num2=0;
        char ch;
        while(bool(s1>>num1)+bool(s2>>num2))
        {
            if(num1>num2)
                return 1;
            if(num2>num1)
                return -1;
            num1=0;
            num2=0;
            s1>>ch;
            s2>>ch;
        }
        if(num1==num2)
            return 0;
        return 0;
    }
};
