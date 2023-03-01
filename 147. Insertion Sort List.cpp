//Approach 1: The most chad solution 🗿.
//Editorial:  No brainer
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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> nums;
        ListNode* temp=head;
        while(temp!=nullptr)
        {
            nums.push_back(temp->val);
            temp=temp->next;
        }
        sort(nums.begin(),nums.end());
        ListNode* newhead=new ListNode();
        ListNode* itr=newhead;
        for(int i=0;i<nums.size();i++)
        {
            ListNode* t=new ListNode(nums[i]);
            itr->next=t;
            itr=itr->next;
        }
        return newhead->next;
    }
};
//Approach 2: Using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode(INT_MIN);
        ListNode* curr=head;
        ListNode* tail=dummy;
        while(curr)
        {
            ListNode* next=curr->next;
            while(tail->next and tail->next->val<curr->val)
                tail=tail->next;
            curr->next=tail->next;
            tail->next=curr;
            tail=dummy;
            curr=next;
        }
        return dummy->next;
    }
};
