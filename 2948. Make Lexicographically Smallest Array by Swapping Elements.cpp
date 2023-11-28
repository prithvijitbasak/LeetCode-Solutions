//Editorial: In the https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/solutions/4330616/c-python-java-explained/
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        // the main inttion behind this is we need to group the elements together
        // that are withing difference limit
        // means in the testcase 
        // [1,7,6,18,2,1]
        // limit = 3
        // we need to group {1, 1, 2} together as these elements are in between limit
        // another group will be {6, 7} and another
        // is {18}
        vector<pair<int,int>> arr;
        int n = nums.size();
        // storing the elements with their indexes
        for(int i=0;i<n;i++)
            arr.push_back({nums[i], i});
        // sorting according to the first element
        sort(arr.begin(), arr.end(), [](const auto &x, const auto &y) {
    return x.first < y.first;
});

        vector<vector<pair<int,int>>> vp = {{arr[0]}};
        // here the grouping is done.
        for(int i=1;i<n;i++)
        {
            if(arr[i].first - arr[i-1].first <= limit)
                vp.back().push_back(arr[i]);
            else
                vp.push_back({arr[i]});
        }

        for(auto it:vp)
        {
            vector<int> idx;
            // atfirst we are sorting the indexes and then we are inserting in the original array
            for(auto it2:it)
                idx.push_back(it2.second);
            sort(idx.begin(), idx.end());
            for(int i=0;i<idx.size();i++)
                nums[idx[i]] = it[i].first;
        }
        return nums;
    }
};
