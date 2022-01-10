//Editorial: Same as (LeetCode problem)307. Range Sum Query - Mutable
class NumArray {
public:
    vector<int> bit,arr;
    void init(int i,int x)
    {
        i++;
        while(i<bit.size())
        {
            bit[i]+=x;
            i+=(i&-i);
        }
    }
    int sum(int i)
    {
        i++;
        int ans=0;
        for(;i>0;i-=(i&-i))
            ans+=bit[i];
        return ans;
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        int n=nums.size();
        bit.resize(n+1,0);
        for(int i=0;i<nums.size();i++)
            init(i,nums[i]);
    }
    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
