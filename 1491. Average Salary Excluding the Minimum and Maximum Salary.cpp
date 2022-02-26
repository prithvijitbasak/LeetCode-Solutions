//Editorial: Just find the largest and smallest element from the array and then find the sum of all elements except the largest and 
//largest and smallest and the return the average of the founded sum with the excluding two elements.
class Solution {
public:
    double average(vector<int>& salary) {
        long long int n=salary.size();
        long long int mxsal=*max_element(salary.begin(),salary.end());
        long long int mnsal=*min_element(salary.begin(),salary.end());
        long long int sum=accumulate(salary.begin(),salary.end(),0);
        sum-=mxsal;
        sum-=mnsal;
        return double(sum*1.0/(n-2));
    }
};
