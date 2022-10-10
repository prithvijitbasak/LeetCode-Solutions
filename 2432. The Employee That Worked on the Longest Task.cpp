//Editorial: Just iterate through the array and keep on updating the value.
class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int sz=logs.size();
        int ans=logs[0][0];
        int maxi=logs[0][1];
        for(int i=1;i<sz;i++)
        {
            if((logs[i][1]-logs[i-1][1])>=maxi)
            {
                if(maxi==logs[i][1]-logs[i-1][1])
                    ans=min(logs[i][0],ans);
                else
                    ans=logs[i][0];
                maxi=logs[i][1]-logs[i-1][1];
            }
        }
        return ans;
    }
};
