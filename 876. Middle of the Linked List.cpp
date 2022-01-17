//Editorial: https://leetcode.com/problems/middle-of-the-linked-list/discuss/154619/C%2B%2BJavaPython-Slow-and-Fast-Pointers
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast and fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
