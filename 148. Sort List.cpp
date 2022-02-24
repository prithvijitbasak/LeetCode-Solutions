//Editorial: using merge sort it can be done in O(nlogn) time and O(n) space.
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
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* newhead=new ListNode(0);
        ListNode* curr=newhead;
        while(l1 and l2)
        {
            if(l1->val>l2->val)
            {
                curr->next=new ListNode(l2->val);
                l2=l2->next;
            }
            else
            {
                curr->next=new ListNode(l1->val);
                l1=l1->next;
            }
            curr=curr->next;
        }
        if(l1)
        {
            curr->next=l1;
        }
        else
            curr->next=l2;
        return newhead->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head or head->next==NULL)
            return head;
        ListNode* fast=head->next,*slow=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        return merge(sortList(head),sortList(fast));
    }
};
