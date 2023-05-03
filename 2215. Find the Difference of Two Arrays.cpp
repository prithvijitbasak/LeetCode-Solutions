//Editorial: Just iterate over the array and update the answer.
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<vector<int>> ans(2);
        set<int> st;
        for(int i=0;i<nums1.size();i++)
        {
            auto it=find(nums2.begin(),nums2.end(),nums1[i]);
            if(it==nums2.end() and st.find(nums1[i])==st.end())
            {
                ans[0].push_back(nums1[i]);
                st.insert(nums1[i]);
            }
        }
        st.clear();
        for(int i=0;i<nums2.size();i++)
        {
            auto it=find(nums1.begin(),nums1.end(),nums2[i]);
            if(it==nums1.end() and st.find(nums2[i])==st.end())
            {
                ans[1].push_back(nums2[i]);
                st.insert(nums2[i]);
            }
        }
        return ans;
    }
};
