//Editorial: https://leetcode.com/problems/candy/solution/
class Solution {
public:
    int count(int n) {
        return (n*(n+1))/2;
    }
    int candy(vector<int>& ratings) {
        int ans=0;
        int n=ratings.size();
        if(n<=1)
            return n;
        int up=0,down=0,oldslope=0;
        for(int i=1;i<ratings.size();i++)
        {
            int newslope=0;
            if(ratings[i]>ratings[i-1])
                newslope=1;
            else if(ratings[i]<ratings[i-1])
                newslope=-1;
            else
                newslope=0;
            if((oldslope>0 and newslope==0) or (oldslope<0 and newslope>=0))
            {
                ans+=count(up)+count(down)+max(up,down);
                up=0;
                down=0;
            }
            if(newslope>0)
                up+=1;
            else if(newslope<0)
                down+=1;
            else
                ans+=1;
            oldslope=newslope;
        }
        ans+=count(up)+count(down)+max(up,down)+1;
        return ans;
    }
};
