//Editorial: https://leetcode.com/problems/merge-nodes-in-between-zeros/discuss/1784739/C%2B%2B-Simulation-O(N)-time
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead=new ListNode(0);
        ListNode* temp=newhead;
        while(head)
        {
            if(head->val==0)
                head=head->next;
            if(!head)
                break;
            int sum=0;
            while(head->val!=0)
            {
                sum+=head->val;
                head=head->next;
            }
            temp->next=new ListNode(sum);
            temp=temp->next;
        }
        return newhead->next;
    }
};
