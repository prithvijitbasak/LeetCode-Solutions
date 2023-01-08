//Editorial: Just check whether the last number was equal to the value. If it was then increase the last frequency by 1 or set it to 0.
class DataStream {
public:
    int last=-1,lastfreq=0,freq,val;
    DataStream(int value, int k) {
        val=value;
        freq=k;
    }
    
    bool consec(int num) {
        int ok=0;
        last=num;
        if(last==val)
            lastfreq+=1;
        else
            lastfreq=0;
        if(last==val and lastfreq>=freq)
            ok=1;
        return ok;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
