//Editorial: https://youtu.be/5rtVTYAk9KQ
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        if(n==0)
          return false;
        if(n&(n-1))
          return false;
        else
          return true;
    }
};
