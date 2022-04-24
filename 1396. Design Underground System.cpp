//Editorial: https://leetcode.com/problems/design-underground-system/discuss/554879/JavaC++-HashMap-and-Pair-Clean-code-O(1)
class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkin;  //id->{stationName,t}
    unordered_map<string,pair<int,int>> checkout; //routeName->{totalTime,count}
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it=checkin[id];
        string route=it.first+"->"+stationName;
        checkout[route].first+=t-it.second;
        checkout[route].second+=1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"->"+endStation;
        auto it=checkout[route];
        return (double)it.first/it.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
