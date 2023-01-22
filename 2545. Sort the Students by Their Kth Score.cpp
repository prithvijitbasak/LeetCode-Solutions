//Editorial: Just sort according to the kth column.
class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m=score.size();
        int n=score[0].size();
        vector<pair<int,int>> marks(m);
        for(int i=0;i<m;i++)
        {
            marks[i].first=score[i][k];
            marks[i].second=i;
        }
        sort(marks.rbegin(),marks.rend());
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            int idx=marks[i].second;
            ans.push_back(score[idx]);
        }
        return ans;
    }
};
