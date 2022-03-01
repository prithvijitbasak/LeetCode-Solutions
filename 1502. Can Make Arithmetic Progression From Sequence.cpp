//Editorial: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/720152/O(n)-time-O(1)-space
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        if(n<=2)
            return true;
        int max=*max_element(arr.begin(),arr.end());
        int min=*min_element(arr.begin(),arr.end());
        int i=0;
        if((max-min)%(n-1)!=0)
            return false;
        int d=(max-min)/(n-1);
        while(i<arr.size())
        {
            if(arr[i]==min+i*d)
                i+=1;
            else if(((arr[i]-min)%d)!=0)
                return false;
            else
            {
                int pos=(arr[i]-min)/d;
                if(arr[pos]==arr[i])
                    return false;
                swap(arr[pos],arr[i]);
            }
        }
        return true;
    }
};
