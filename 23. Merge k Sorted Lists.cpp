//Editorial: https://leetcode.com/problems/merge-k-sorted-lists/discuss/611161/Fast-C%2B%2B-solution-(95)-with-comments-and-explanation!-Uses-MinHeap, https://youtu.be/kpCesr9VXDA
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        map<int,int> mp;
        for(int i=0;i<lists.size();i++)
        {
            auto it=lists[i];
            while(it)
            {
                mp[it->val]++;
                it=it->next;
            }
        }
        ListNode newhead(0);
        ListNode *temp=&newhead;
        for(auto it:mp)
        {
            while(it.second)
            {
                temp->next=new ListNode(it.first);
                it.second--;
                temp=temp->next;
            }
        }
        return newhead.next;
    }
};
