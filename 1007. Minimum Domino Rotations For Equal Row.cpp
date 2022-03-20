//Editorial: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/901333/C%2B%2B-super-simple-and-easy-short-explained-solution-O(n)-time-O(1)-space
class Solution {
public:
    int getminopt(vector<int> &a,vector<int> &b,int val)
    {
        int cnta=0,cntb=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]!=val and b[i]!=val)
                return -1;
            if(a[i]!=val)
                cnta+=1;
            if(b[i]!=val)
                cntb+=1;
        }
        return min(cnta,cntb);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int type1=getminopt(tops,bottoms,tops[0]);
        int type2=getminopt(tops,bottoms,bottoms[0]);
        if(min(type1,type2)<0)
            return max(type1,type2);
        else
            return min(type1,type2);
    }
};
