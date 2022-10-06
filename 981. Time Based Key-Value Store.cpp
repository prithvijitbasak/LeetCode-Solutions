//Editorial: https://leetcode.com/problems/time-based-key-value-store/solution/
class TimeMap {
public:
    map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)==mp.end())
            return "";
        if(timestamp<mp[key][0].first)
            return "";
        int low=0,high=mp[key].size();
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(mp[key][mid].first<=timestamp)
                low=mid+1;
            else
                high=mid;
        }
        if(high==0)
            return "";
        return mp[key][high-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
