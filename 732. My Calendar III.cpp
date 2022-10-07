//Editorial: https://youtu.be/_7B_HzJUE6E
class MyCalendarThree {
public:
    map<int,int> events;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        events[start]+=1;
        events[end]-=1;
        int sum=0,ans=0;
        for(auto it:events)
        {
            sum+=it.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
