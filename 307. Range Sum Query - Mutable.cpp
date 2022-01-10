//Editorial: https://leetcode.com/problems/range-sum-query-mutable/discuss/927800/Segment-Tree-and-Binary-Indexed-Tree-Solution-C%2B%2B
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
        while(i>0)
        {
            ans+=bit[i];
            i-=(i&-i);
        }
        return ans;
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        int n=nums.size();
        bit.resize(n+1,0);
        for(int i=0;i<nums.size();i++)
            init(i,nums[i]);
    }
    
    void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        init(index,diff);
    }
    
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
