//Approach 1: Brute-force to count the number of 1's in each row and then arrange in ascending order. TC: O(m*n) SC O(n)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> weakrow;
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                    break;
                else
                    cnt+=1;
            }
            weakrow.push_back({cnt,i});
        }
        sort(weakrow.begin(),weakrow.end());
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(weakrow[i].second);
        }
        return ans;
    }
};
//Approach 2: Max-heap + Binary-search
//Editorial: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/1066773/C%2B%2B-or-Max-Heap-%2B-Binary-Search-or-O(m*log(max(n-k))-0ms-Beats-100-or-Explanation-(Tips)
class Solution {
public:
    int search(vector<int> arr)
    {
        int n=arr.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]==0)
                high=mid-1;
            else 
                low=mid+1;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxh;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int idx=search(mat[i]);
            maxh.push({idx,i});
            if(maxh.size()>k)
                maxh.pop();
        }
        vector<int> ans;
        while(!maxh.empty())
        {
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
