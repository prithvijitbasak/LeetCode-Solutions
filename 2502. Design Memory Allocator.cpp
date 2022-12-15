//Editorial: https://leetcode.com/problems/design-memory-allocator/solutions/2899383/c-simple-iterative-using-vector-very-simple-and-easy-to-understand/?orderBy=most_votes
class Allocator {
public:
    vector<int> arr;
    Allocator(int n) {
        arr.resize(n,0);
    }
    
    int allocate(int size, int mID) {
        int start=-1;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==0)
            {
                if(cnt==0)
                    start=i;
                cnt+=1;
                if(cnt>=size)
                {
                    for(int j=0;j<size;j++)
                        arr[start+j]=mID;
                    return start;
                }
            }
            else
            {
                cnt=0;
                start=i;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==mID)
            {
                arr[i]=0;
                cnt+=1;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
