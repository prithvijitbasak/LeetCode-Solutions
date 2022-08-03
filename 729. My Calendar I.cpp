//Editorial: https://leetcode.com/problems/my-calendar-i/discuss/1262664/Easy-Solutions-w-Explanation-and-Diagram-or-Brute-Force-and-Binary-Search-Approach
//Approach 1: Brute force. TC: O(n) SC: O(n)
class MyCalendar {
public:
    unordered_map<int,int> ump;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it:ump)
        {
            if(!(start>=it.second or end<=it.first))
                return false;
        }
        ump[start]=end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
//Approach 2:  Using binary-search. TC: O(logn) SC: O(n)
class MyCalendar {
public:
    set<pair<int,int>> ump;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto slot=ump.lower_bound({start,end});
        if(slot!=ump.end() and !(slot->first>=end) or (slot!=ump.begin() and !(prev(slot)->second<=start)))
            return false;
        ump.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
