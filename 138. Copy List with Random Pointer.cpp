//Editorial: https://youtu.be/VNf6VynfpdM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter=head,*front=head;
        while(iter)
        {
            front=iter->next;
            Node* copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        while(iter)
        {
            if(iter->random)
            {
                iter->next->random=iter->random->next;
            }
            iter=iter->next->next;
        }
        iter=head;
        Node* newhead=new Node(0);
        Node* copy=newhead;
        while(iter)
        {
            front=iter->next->next;
            copy->next=iter->next;
            iter->next=front;
            copy=copy->next;
            iter=iter->next;
        }
        return newhead->next;
    }
};
