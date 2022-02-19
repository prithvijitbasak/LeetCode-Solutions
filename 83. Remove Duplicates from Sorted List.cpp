// Approach 1: Without using deleting the duplicates.
// Editorial: Just change their next nodes with current nodes.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr)
        {
            while(curr->next and curr->val==curr->next->val)
                curr->next=curr->next->next;
            curr=curr->next;
        }
        return head;
    }
};
// Approach 2: Using delete keyword.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr=head;
        while(curr)
        {
            while(curr->next and curr->val==curr->next->val)
            {
                ListNode* temp=curr->next;
                curr->next=temp->next;
                delete temp;
            }
            curr=curr->next;
        }
        return head;
    }
};
