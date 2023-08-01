class ParkingSystem {
public:
    int car[3];
    ParkingSystem(int big, int medium, int small) {
        this->car[0] = big;
        this->car[1] = medium;
        this->car[2] = small;
    }
    
    bool addCar(int carType) {
        if (car[carType - 1]) {
            car[carType - 1]--;
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