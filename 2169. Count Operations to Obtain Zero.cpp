//Editorial: Just keep on doing the operations until you hit zero in any of the number.
class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt=0;
        while(1)
        {
            if(num1==0 or num2==0)
                  break;
            if(num1>=num2)
                num1-=num2;
            else
                num2-=num1;
            cnt+=1;
        }
        return cnt;
    }
};
