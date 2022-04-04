//Editorial: Just reach to the required nodes and swap the values.
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
    ListNode* swapNodes(ListNode* head, int k) {
        int start=0;
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len+=1;
            temp=temp->next;
        }
        int end=len;
        temp=head;
        ListNode* tail=head;
        end=0;
        while(end<len-k)
        {
            tail=tail->next;
            end+=1;
        }
        temp=head;
        while(start<k-1)
        {
            temp=temp->next;
            start+=1;
        }
        swap(temp->val,tail->val);
        return head;
    }
};
