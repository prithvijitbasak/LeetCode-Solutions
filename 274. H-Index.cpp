//Editorial: https://leetcode.com/problems/h-index/discuss/70768/Java-bucket-sort-O(n)-solution-with-detail-explanation
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> buckets(n+1);
        for(auto it:citations)
        {
            if(it>=n)
                buckets[n]+=1;
            else
                buckets[it]+=1;
        }
        int cnt=0;
        for(int i=n;i>=0;i--)
        {
            cnt+=buckets[i];
            if(cnt>=i)
                return i;
        }
        return -1;
    }
};
