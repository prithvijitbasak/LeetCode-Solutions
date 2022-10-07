//Editorial: https://youtu.be/_7B_HzJUE6E
class MyCalendarTwo {
public:
    map<int,int> events;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        events[start]+=1;
        events[end]-=1;
        int sum=0;
        for(auto it:events)
        {
            sum+=it.second;
            if(sum==3)
            {
                events[start]-=1;
                events[end]+=1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
