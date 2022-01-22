//Ediotrial: https://youtu.be/S5doKK6KDWM
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode newhead(0),*pt=&newhead;
        while(list1 or list2)
        {
            if(!list2 or (list1 and list1->val<=list2->val))
            {
                pt->next=new ListNode(list1->val);
                pt=pt->next;
                list1=list1->next;
            }
            else
            {
                pt->next=new ListNode(list2->val);
                list2=list2->next;
                pt=pt->next;
            }
        }
        return newhead.next;
    }
};
