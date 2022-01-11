//Editorial: Same as (LeetCode problem)307. Range Sum Query - Mutable
// Using Segment tree
class NumArray {
public:
    vector<int> seg,arr;
    int n;
    void build(int idx,int left,int right)
    {
        if(left==right)
        {
            seg[idx]=arr[left];
            return;
        }
        int mid=(left+right)/2;
        build(2*idx+1,left,mid);
        build(2*idx+2,mid+1,right);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
    int rangesum(int pos,int low,int high,int left,int right)
    {
        if(left<=low and right>=high)
            return seg[pos];
        if(low>right or high<left)
            return 0;
        int mid=(low+high)/2;
        return rangesum(2*pos+1,low,mid,left,right)+rangesum(2*pos+2,mid+1,high,left,right);
    }
    NumArray(vector<int>& nums) {
        arr=nums;
        n=nums.size();
        seg.resize(4*n,0);
        build(0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return rangesum(0,0,n-1,left,right);
    }
};

// Using Fenwick tree
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
