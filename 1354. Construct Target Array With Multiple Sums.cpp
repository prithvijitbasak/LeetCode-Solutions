//Editorial: https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/1199223/JS-Python-Java-C++-or-Easy-Max-PriorityQueueHeap-Solution-w-Explanation
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long int sum=0;
        for(auto it:target)
        {
            sum+=it;
            pq.push(it);
        }
        while(pq.top()!=1)
        {
            int val=pq.top();
            pq.pop();
            sum-=val;
            if(val<=sum or sum<1)
                return false;
            val%=sum;
            sum+=val;
            if(val)
                pq.push(val);
            else
                pq.push(sum);
        }
        return true;
    }
};
