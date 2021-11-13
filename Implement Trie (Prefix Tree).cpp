//Editorial: https://youtu.be/dBGUmUQhjaM
struct Node{
    Node* links[26];
    bool flag=false;
    bool containskey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void putnode(char ch,Node *temp)
    {
        links[ch-'a']=temp;
    }
    Node* getnode(char ch)
    {
        return links[ch-'a'];
    }
    void setend()
    {
        flag=true;
    }
    bool isend()
    {
        return flag;
    }
};
class Trie {
    private: Node* root; 
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containskey(word[i]))
                temp->putnode(word[i],new Node());
            temp=temp->getnode(word[i]);
        }
        temp->setend();
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containskey(word[i]))
                return false;
            temp=temp->getnode(word[i]);
        }
        return temp->isend();
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->containskey(prefix[i]))
                return false;
            temp=temp->getnode(prefix[i]);
        }
        return true;
    }
};
