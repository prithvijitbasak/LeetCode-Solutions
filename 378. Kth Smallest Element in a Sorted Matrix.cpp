// Approach 1: By using max-heap. TC: O(m*n*logk) SC: O(k)
// Editorial: Just keep on pushing all the elements in a max-heap until its size is upto k and whenever the size exceeds k just
// pop the topmost element.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                    pq.pop();
            }
        }
        return pq.top();
    }
};
//Approach 2: Using binary-search. TC: O(n*logn*logn) SC: O(1)
// Editorial: https://youtu.be/w36ekZYq-Ms
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<high)
        {
            int mid=low+(high-low)/2;
            int cnt=0;
            for(int i=0;i<n;i++)
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            if(cnt<k)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
