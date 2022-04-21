//Editorial: https://leetcode.com/problems/design-hashset/discuss/773006/C++-3-Approaches
class MyHashSet {
public:
    vector<int> nums;
    MyHashSet() {
        nums.resize(1e6+1,0);
    }
    
    void add(int key) {
        nums[key]=1;
    }
    
    void remove(int key) {
        nums[key]=0;
    }
    
    bool contains(int key) {
        return nums[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
