//Editorial: https://youtu.be/ey8FxYsFAMU, https://leetcode.com/problems/course-schedule-iii/discuss/1187504/JS-Python-Java-C++-or-Simple-Priority-Queue-Heap-Solution-w-Explanation
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;
        int ans=0;
        int total=0;
        sort(courses.begin(),courses.end(), [](auto &a,auto &b){return a[1]<b[1];});
        int n=courses.size();
        for(int i=0;i<n;i++)
        {
            int dur=courses[i][0],end=courses[i][1];
            if(total+dur<=end)
            {
                total+=dur;
                pq.push(dur);
            }
            else if(!pq.empty() and pq.top()>dur)
            {
                total+=dur-pq.top();
                pq.pop();
                pq.push(dur);
            }
        }
        return pq.size();
    }
};
