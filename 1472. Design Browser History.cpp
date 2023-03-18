//Editorial: https://leetcode.com/problems/design-browser-history/editorial/
class BrowserHistory {
public:
    vector<string> urls;
    int curr;
    int last;
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        curr=0;
        last=0;
    }
    
    void visit(string url) {
        curr+=1;
        if(urls.size()>curr)
            urls[curr]=url;
        else
            urls.push_back(url);
        last=curr;
    }
    
    string back(int steps) {
        curr=max(0,curr-steps);
        return urls[curr];
    }
    
    string forward(int steps) {
        curr=min(last,curr+steps);
        return urls[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
