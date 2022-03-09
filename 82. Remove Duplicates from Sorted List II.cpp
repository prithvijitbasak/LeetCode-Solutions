//Editorial: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solution/
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        while(head)
        {
            if(head->next and head->val==head->next->val)
            {
                while(head->next and head->val==head->next->val)
                    head=head->next;
                prev->next=head->next;
            }
            else
                prev=prev->next;
            head=head->next;
        }
        return dummy->next;
    }
};
