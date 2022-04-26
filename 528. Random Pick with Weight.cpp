//Editorial: https://youtu.be/fWS0TCcr-lE
class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& w) {
        nums.push_back(w[0]);
        for(int i=1;i<w.size();i++)
            nums.push_back(w[i]+nums.back());
    }
    
    int pickIndex() {
        int rw=rand()%(nums.back());
        return upper_bound(nums.begin(),nums.end(),rw)-nums.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
