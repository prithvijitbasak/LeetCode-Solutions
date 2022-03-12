//Editorial: https://youtu.be/9VPm6nEbVPA
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* newhead=head;
        ListNode *tail=head;
        int len=1;
        while(tail->next)
        {
            tail=tail->next;
            len+=1;
        }
        tail->next=head;
        if(k%=len)
        {
            for(int i=0;i<len-k;i++)
                tail=tail->next;
        }
        newhead=tail->next;
        tail->next=NULL;
        return newhead;
    }
};
