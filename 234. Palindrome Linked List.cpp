//Editorial: https://youtu.be/-DtNInqFUXs
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
    ListNode* reverselist(ListNode* head)
    {
        ListNode *newhead=NULL;
        while(head)
        {
            ListNode* temp=head->next;
            head->next=newhead;
            newhead=head;
            head=temp;
        }
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode* fast=head,*slow=head;
        while(fast->next and fast->next->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=reverselist(slow->next);
        slow=slow->next;
        while(slow)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
};
