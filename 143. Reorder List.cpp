//Editorial: https://leetcode.com/problems/reorder-list/solutions/802119/c-really-simple-solution-using-stack-with-explanations/?orderBy=most_votes
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
    void reorderList(ListNode* head) {
        if(head==nullptr or head->next==nullptr or head->next->next==nullptr)
            return;
        stack<ListNode*> stk;
        ListNode* temp=head;
        int sz=0;
        while(temp!=nullptr)
        {
            stk.push(temp);
            sz+=1;
            temp=temp->next;
        }
        ListNode* curr=head;
        for(int i=0;i<sz/2;i++)
        {
            ListNode* ele=stk.top();
            stk.pop();
            ele->next=curr->next;
            curr->next=ele;
            curr=curr->next->next;
        }
        curr->next=nullptr;
    }
};
