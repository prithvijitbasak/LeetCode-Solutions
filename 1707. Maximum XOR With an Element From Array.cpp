//Editorial: https://youtu.be/Q8LhG9Pi5KM
struct Node {
    Node *links[2]; 
    bool containsKey(int idx) 
    {
        return links[idx]; 
    }
    Node* get(int idx) 
    {
        return links[idx]; 
    }
    void put(int idx, Node* temp) 
    {
        links[idx] = temp; 
    }
}; 
class Trie {
    private: 
    Node* root; 
public:
    Trie() 
    {
        root = new Node(); 
    }
    void insert(int num) 
    {
        Node* temp=root; 
        for(int i = 31;i>=0;i--) 
        {
            int bit = (num >> i) & 1; 
            if(!temp->containsKey(bit)) 
                temp->put(bit, new Node()); 
            temp = temp->get(bit); 
        }
    }
    int findMax(int num) {
        Node* temp = root; 
        int ans=0; 
        for(int i = 31;i>=0;i--) 
        {
            int bit = (num >> i) & 1; 
            if(temp->containsKey(!bit))
            {
                ans+=(1<<i); 
                temp = temp->get(!bit); 
            }
            else 
                temp = temp->get(bit); 
        }
        return ans; 
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int> ans(n,0);
        vector<pair<int,pair<int,int>>> oq;
        sort(nums.begin(),nums.end());
        int idx=0;
        for(auto it:queries)
            oq.push_back({it[1],{it[0],idx++}});
        sort(oq.begin(),oq.end());
        Trie trie;
        int i=0;
        int sz=nums.size();
        for(auto it:oq)
        {
            while(i<sz and nums[i]<=it.first)
            {
                trie.insert(nums[i]);
                i++;
            }
            if(i!=0)
                ans[it.second.second]=trie.findMax(it.second.first);
            else
                ans[it.second.second]=-1;
        }
        return ans;
    }
};
