//Editorial: Just map the months to their numbers and append it to the solution.
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string,string> ump={{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        int n=date.size();
        string ans="";
        // int day;
        if(n==13)
            ans+=date.substr(9,4);
        else
            ans+=date.substr(8,4);
        ans+='-';
        string month=(n==13)?date.substr(5,3):date.substr(4,3);
        ans+=(ump[month]);
        ans+='-';
        int day=(n==13)?stoi(date.substr(0,2)):stoi(date.substr(0,1));
        if(day<10)
            ans+=(to_string(0)+to_string(day));
        else
            ans+=to_string(day);
        return ans;
    }
};
