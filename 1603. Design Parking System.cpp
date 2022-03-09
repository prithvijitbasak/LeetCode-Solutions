//Editorial: https://leetcode.com/problems/design-parking-system/discuss/876927/C%2B%2B-Python-Explained-oror-Easy-Understanding-oror
class ParkingSystem {
public:
    vector<int> spaces;
    ParkingSystem(int big, int medium, int small) {
        spaces={big,medium,small};
    }
    
    bool addCar(int carType) {
        if(spaces[carType-1])
        {
            spaces[carType-1]-=1;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
