//Method 1:
//Editorial: https://leetcode.com/problems/swap-nodes-in-pairs/discuss/11183/C%2B%2B-solution-with-graph-explanation.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *newhead=new ListNode(0);
        newhead->next=head;
        ListNode *prev=newhead,*curr=head;
        while(curr and curr->next)
        {
            prev->next=curr->next;
            prev=prev->next;
            curr->next=prev->next;
            prev->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return newhead->next;
    }
};
//Method 2:
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
    ListNode* swapPairs(ListNode* head) {
        int k=2;
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
