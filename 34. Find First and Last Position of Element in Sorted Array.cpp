//Editorial: In the solution.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int n = nums.size();
        int l = 0, r = n - 1;
        // for finding the first occurence of the target
        while(l <= r)
        {
            // the intuition is the every element in the array is 
            // occuring either once or more than once
            // if we need to find the first occurence then 
            // we will just find by doing binary searching and 
            // if we find the mid element as the target element 
            // and then we will just reduce the right search space by doing
            // r = mid - 1;
            // because we know that the elements in the right of the mid will always 
            // be the target as it is non-decreasing and will store it 
            // in the answer variable
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
            {
                ans[0] = mid;
                r = mid - 1;
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        l = 0;
        r = n - 1;
        // for finding the last occurence of the target
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            // same as the above but here we are doing 
            // making the left search space to l = mid - 1;
            // the concept is same as above
            if(nums[mid] == target)
            {
                ans[1] = mid;
                l = mid + 1;
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }
};
