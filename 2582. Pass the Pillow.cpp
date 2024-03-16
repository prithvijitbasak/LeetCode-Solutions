// Editorial: In the solution
class Solution {
public:
    int passThePillow(int n, int time) {
        // tutorial: https://leetcode.com/problems/pass-the-pillow/solutions/4174923/beats-100-begnieer-friendly-easy-c-code-o-1-time-and-space

        
        // to find the number of remaining pass we need to divide the time by n-1
        // as the number of pass we need to transfer the pillow from 1 to n is n-1
        int remainingPass = time % (n-1);

        // if the pillow is at the begining then the remiander divided by 2 is always 0
        if((time/(n-1))%2 == 0)
            return remainingPass + 1;
        // the pillow is at the end 
        else
            return n - remainingPass;

    }
};
