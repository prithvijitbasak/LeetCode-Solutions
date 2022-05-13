//Editorial: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/38015/Simple-40ms-c++-o(n)-o(1)-solution-with-only-one-while-loop
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* curr=root;
        Node* head=nullptr;
        Node* tail=nullptr;
        while(curr)
        {
            if(curr->left)
            {
                if(tail)
                {
                    tail->next=curr->left;
                    tail=tail->next;
                }
                else
                {
                    head=curr->left;
                    tail=curr->left;
                }
            }
            if(curr->right)
            {
                if(tail)
                {
                    tail->next=curr->right;
                    tail=tail->next;
                }
                else
                {
                    head=curr->right;
                    tail=curr->right;
                }
            }
            curr=curr->next;
            if(!curr)
            {
                curr=head;
                head=tail=nullptr;
            }
        }
        return root;
    }
};
