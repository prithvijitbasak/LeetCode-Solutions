//Editorial: Old school merge sort method.
class Solution {
public:
    void merge(vector<int> &nums,int low,int mid,int high)
    {
        vector<int> temp;
        int left=low;
        int right=mid+1;
        while(left<=mid and right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left]);
                left+=1;
            }
            else
            {
                temp.push_back(nums[right]);
                right+=1;
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left]);
            left+=1;
        }
        while(right<=high)
        {
            temp.push_back(nums[right]);
            right+=1;
        }
        for(int i=low;i<=high;i++)
            nums[i]=temp[i-low];
    }
    void mergesort(vector<int> &nums,int low,int high)
    {
        if(low>=high)
            return;
        int mid=low+(high-low)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        mergesort(nums,0,n-1);
        return nums;
    }
};
