//Editorial: https://leetcode.com/problems/data-stream-as-disjoint-intervals/solutions/2866931/data-stream-as-disjoint-intervals/?orderBy=most_votes
class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> temp;
        for(auto it:st)
            temp.push_back(it);
        int n=temp.size();
        for(int i=0;i<n;)
        {
            int start=i,end=i;
            while(end+1<n and temp[end+1]==temp[end]+1)
                end+=1;
            if(end>start)
                ans.push_back({temp[start],temp[end]});
            else
                ans.push_back({temp[end],temp[end]});
            i=end+1;
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
