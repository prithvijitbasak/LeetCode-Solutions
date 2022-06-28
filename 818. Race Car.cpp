//Editorial: https://leetcode.com/problems/race-car/discuss/762584/Python-C++-3-Simple-Steps-(BFS)
class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0,0,1}); // moves, position and velocity.
        while(!q.empty())
        {
            vector<int> val=q.front();
            q.pop();
            int moves=val[0];
            int pos=val[1];
            int vel=val[2];
            if(pos==target)
                return moves;
            if(abs(pos)>2*target)
                continue;
            q.push({moves+1,pos+vel,2*vel});
            if((pos+vel>target and vel>0) or (pos+vel<target and vel<0))
                q.push({moves+1,pos,(vel>0)?-1:1});
        }
        return 0;
    }
};
