//Editorial: https://youtu.be/Of0HPkk3JgI
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL or k==1)
            return head;
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        ListNode* curr=newhead,*prev=newhead,*nex=newhead;
        int cnt=0;
        while(curr->next)
        {
            cnt++;
            curr=curr->next;
        }
        curr=newhead;
        while(k<=cnt)
        {
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<=k-1;i++)
            {
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            cnt-=k;
            prev=curr;
        }
        return newhead->next;
    }
};
