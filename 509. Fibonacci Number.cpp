//Approach 1: Brute-force or recursive approach. TC: O(n^2) SC: O(n)
//Editorial: https://leetcode.com/problems/fibonacci-number/discuss/218301/C%2B%2B-4-Solutions-Explained-Recursive-or-Iterative-with-DP-or-Imperative-or-Binet's
class Solution {
public:
    int fib(int n) {
        if(n==0 or n==1)
            return n;
        return fib(n-1)+fib(n-2);
    }
};
//Approach 2: Using bottom up dp. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/fibonacci-number/discuss/218301/C%2B%2B-4-Solutions-Explained-Recursive-or-Iterative-with-DP-or-Imperative-or-Binet's
class Solution {
public:
    int fib(int n) {
        vector<int> fib(n+1);
        if(n==0 or n==1)
            return n;
        fib[0]=0;
        fib[1]=1;
        for(int i=2;i<=n;i++)
            fib[i]=fib[i-1]+fib[i-2];
        return fib[n];
    }
};
//Approach 3: Using bottom-up dp with space-optimisation. TC: O(n) SC: O(1)
////Editorial: https://leetcode.com/problems/fibonacci-number/discuss/218301/C%2B%2B-4-Solutions-Explained-Recursive-or-Iterative-with-DP-or-Imperative-or-Binet's
class Solution {
public:
    int fib(int n) {
        if(n==0 or n==1)
            return n;
        int a=0,b=1,c=0;
        for(int i=1;i<n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
// Approach 4: Using Binet's formula to find the nth fibonacci number.
//Editorial: https://leetcode.com/problems/fibonacci-number/discuss/218301/C%2B%2B-4-Solutions-Explained-Recursive-or-Iterative-with-DP-or-Imperative-or-Binet's
class Solution {
public:
    int fib(int n) {
        double phi=(sqrt(5)+1)/2;
        int ans=round(pow(phi,n)/sqrt(5));
        return ans;
    }
};
