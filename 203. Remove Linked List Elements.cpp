//Editorial: https://leetcode.com/problems/remove-linked-list-elements/discuss/1572892/C%2B%2BPython-Clean-and-Simple-Solution-w-Explanation-and-Illustration-or-Iterative-and-Recursive
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* newhead=new ListNode(0,head),*prev=newhead;
        for(;head;head=head->next)
        {
            if(head->val!=val)
                prev=head;
            else
                prev->next=head->next;
        }
        return newhead->next;
    }
};
