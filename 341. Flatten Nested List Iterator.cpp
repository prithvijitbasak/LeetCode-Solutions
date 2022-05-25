//Editorial: https://youtu.be/V-gPWPOyq8I
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> nums;
    int curr=0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(auto it:nestedList)
            helper(it);
    }
    
    int next() {
        return nums[curr++];
    }
    
    bool hasNext() {
        return curr<nums.size();
    }
    void helper(NestedInteger val)
    {
        if(val.isInteger())
            nums.push_back(val.getInteger());
        else
        {
            for(auto it:val.getList())
                helper(it);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
