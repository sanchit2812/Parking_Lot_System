#include "Car.h"
#include "Driver.h"

//Derived Class
class CarDriver: public Car, public Driver {

    private:
        int num;

    public:

//setNum is a function to set the num
        void setNum (int y){
            num = y;
        }
//getNum is a function to get the num
        int getNum(){
            return num;
        }
};
