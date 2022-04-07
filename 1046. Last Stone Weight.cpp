//Editorial: Just add all those elements in the max heap and find the answer. Go through the solution to get more clarity.
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it:stones)
            pq.push(it);
        while(pq.size()>1)
        {
            int f=pq.top();
            pq.pop();
            int s=pq.top();
            pq.pop();
            pq.push(f-s);
        }
        return pq.top();
    }
};
