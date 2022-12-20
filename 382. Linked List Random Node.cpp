//Editorial: https://youtu.be/FoHIX3URFaM
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
    ListNode* headnode;
    int len=0;
    Solution(ListNode* head) {
        headnode=head;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            len+=1;
        }
    }
    
    int getRandom() {
        ListNode* temp=headnode;
        int idx=rand()%len;
        for(int i=0;i<idx;i+=1)
            temp=temp->next;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
