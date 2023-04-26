//Editorial: https://leetcode.com/problems/smallest-number-in-infinite-set/solutions/2261300/full-explanations-c-set-easy-to-understand-also-java-python-code/?orderBy=most_votes
class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        st.clear();
        for(int i=1;i<=1000;i++)
            st.insert(i);
    }
    
    int popSmallest() {
        int value = *st.begin();
        st.erase(value);
        return value;
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
