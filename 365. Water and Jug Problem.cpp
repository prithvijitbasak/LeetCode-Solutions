//Approach 1: Using BFS.
//Editorial: https://leetcode.com/problems/water-and-jug-problem/discuss/1055738/VMware-asked-this-in-Interview.-My-BFS-solution-for-interview.
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target)
            return false;
        if(x+y==target or x==target or y==target)
            return true;
        if(x%2==0 and y%2==0 and target%2!=0)
            return false;
        set<pair<int,int>> vis;
        queue<pair<int,int>> q;
        q.push({x,y});
        vis.insert({x,y});
        while(!q.empty())
        {
            int currx=q.front().first;
            int curry=q.front().second;
            q.pop();
            if(currx+curry==target or currx==target or curry==target)
                return true;
            int newx,newy;
            //pouring x->y
            newx=currx-min(currx,y-curry);
            newy=curry+min(currx,y-curry);
            if(vis.find({newx,newy})==vis.end())
            {
                q.push({newx,newy});
                vis.insert({newx,newy});
            }
            //pouring y->x
            newx=currx+min(x-currx,curry);
            newy=curry-min(x-currx,curry);
            if(vis.find({newx,newy})==vis.end())
            {
                q.push({newx,newy});
                vis.insert({newx,newy});
            }
            //empty x
            newx=0;
            newy=curry;
            if(vis.find({newx,newy})==vis.end())
            {
                q.push({newx,newy});
                vis.insert({newx,newy});
            }
            //empty y
            newx=currx;
            newy=0;
            if(vis.find({newx,newy})==vis.end())
            {
                q.push({newx,newy});
                vis.insert({newx,newy});
            }
            //fill x completely
            newx=x;
            newy=curry;
            if(vis.find({newx,newy})==vis.end())
            {
                q.push({newx,newy});
                vis.insert({newx,newy});
            }
            //fill y completely
            newx=currx;
            newy=y;
            if(vis.find({newx,newy})==vis.end())
            {
                q.push({newx,newy});
                vis.insert({newx,newy});
            }
        }
        return false;
    }
};
//Approach 2: Using GCD.
class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target)
            return false;
        if(x+y==target or x==target or y==target)
            return true;
        if(x%2==0 and y%2==0 and target%2!=0)
            return false;
        return target%__gcd(x,y)==0;
    }
};
