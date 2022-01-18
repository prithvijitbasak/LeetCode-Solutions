//Editorial: https://leetcode.com/problems/add-two-numbers/discuss/997/c%2B%2B-Sharing-my-11-line-c%2B%2B-solution-can-someone-make-it-even-more-concise
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newhead=new ListNode(0);
        ListNode *p=newhead;
        int carry=0;
        while(l1 or l2 or carry)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            carry=sum/10;
            p->next=new ListNode(sum%10);
            p=p->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return newhead->next;
    }
};
