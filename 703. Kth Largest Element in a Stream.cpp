//Editorial: https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/150609/C%2B%2B-super-easy-28ms-solution-beats-100!
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minh;
    int req;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums)
        {
            minh.push(it);
            if(minh.size()>k)
                minh.pop();
        }
        req=k;
    }
    
    int add(int val) {
        minh.push(val);
        if(minh.size()>req)
            minh.pop();
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
