//Editorial: https://youtu.be/EIhAwfHubE8, https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/1722683/C%2B%2B-Trie-Solution-or-Intuition-or-O(nlog(m))
class Node{
    public:
    Node* child[2];
    Node()
    {
        this->child[0]=NULL;
        this->child[1]=NULL;
    }
};
class Solution {
public:
    Node* root=new Node();
    
    void insert(int val)
    {
        Node* temp=root;
        bitset<32> bits(val);
        for(int i=31;i>=0;i--)
        {
            if(!temp->child[bits[i]])
                temp->child[bits[i]]=new Node();
            temp=temp->child[bits[i]];
        }
    }
    int maxxor(int val)
    {
        Node* temp=root;
        bitset<32> bits(val);
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(temp->child[!bits[i]])
            {
                ans+=(1<<i);
                temp=temp->child[!bits[i]];
            }
            else
                temp=temp->child[bits[i]];
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        for(auto it:nums)
            insert(it);
        int ans=0;
        for(auto it:nums)
            ans=max(ans,maxxor(it));
        return ans;
    }
};
