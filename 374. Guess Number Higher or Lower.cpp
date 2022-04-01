//Editorial: https://leetcode.com/problems/guess-number-higher-or-lower/solution/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1,high=n;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(guess(mid)==0)
                return mid;
            if(guess(mid)==1)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};
