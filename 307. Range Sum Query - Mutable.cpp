// Using Segment tree
//Editorial: https://leetcode.com/problems/range-sum-query-mutable/discuss/1218358/C%2B%2B-or-Segment-Tree-or-Explained
class NumArray {
public:
    vector<int> seg,arr;
    int n;
    void build(int idx,int low,int high)
    {
        if(low==high)
        {
            seg[idx]=arr[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid);
        build(2*idx+2,mid+1,high);
        seg[idx]=(seg[2*idx+1]+seg[2*idx+2]);
    }
    void updateUtil(int pos,int low,int high,int index,int val)
    {
        if(index>high or index<low)
            return;
        if(low==high)
        {
            if(low==index)
            {
                seg[pos]=val;
            }
            return;
        }
        int mid=(low+high)/2;
        updateUtil(2*pos+1,low,mid,index,val);
        updateUtil(2*pos+2,mid+1,high,index,val);
        seg[pos]=seg[2*pos+1]+seg[pos*2+2];
    }
    int rangesum(int pos,int low,int high,int left,int right)
    {
        if(left<=low and high<=right)
            return seg[pos];
        if(high<left or low>right)
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
    
    void update(int index, int val) {
        updateUtil(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return rangesum(0,0,n-1,left,right);
    }
};
// Using Fenwick tree
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
