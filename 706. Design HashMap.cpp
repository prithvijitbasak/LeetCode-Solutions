//Editorial: Just create a vector of pair values 0 and -1 and keepo on updating the values.
class MyHashMap {
public:
    vector<pair<int,int>> nums;
    MyHashMap() {
        nums.resize(1e6+1,{0,-1});
    }
    
    void put(int key, int value) {
        nums[key]={1,value};
    }
    
    int get(int key) {
        return nums[key].second;
    }
    
    void remove(int key) {
        nums[key]={0,-1};
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
