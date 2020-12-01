#include "Car.h"
#include "Driver.h"

//Derived Class
class CarDriver: public Car, public Driver {

    private:
// if status == 1 then car is parked on that slot, else if status == -1 then car is vacant on that slot
        int status;

    public:

//setNum is a function to set the status
        void setStatus (int y){
            status = y;
        }
//getNum is a function to get the status
        int getStatus(){
            return status;
        }
};
