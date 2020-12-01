#include <iostream>
#include <vector>
using namespace std;

#include "CarDriver.h"

// Class declaration for Parking_Lot
class ParkingLot{

    public:
        int Capacity = 0;
        int ParkingId =0;
        int TotalOccupiedSpace =0;

        vector<CarDriver> slotsDetails;// vector initialization for derived class

        int createParkingLot(int capacity); // Constructor initialization for createParkingLot
        int getUnoccupied();//Constructor initialization for getUnoccupied
        int parkCar(string Regno, int age);//Constructor initialization for parkCar
        pair<string,int> leave(int ParkingId);//Constructor initialization for leave
        vector <string> getRegNoFromAge(int age);//Constructor initialization for getRegNoFromAge
        int getSlotNoFromRegNo(string Regno);//Constructor initialization for getSlotNoFromRegNo
        vector<int> getSlotNoFromAge(int age);//Constructor initialization for getSlotNoFromAge

};

//Function for Constructor createParkingLot
int ParkingLot::createParkingLot(int capacity){

    slotsDetails.resize(capacity);

    for(int i=0;i<capacity;i++) slotsDetails[i].setStatus(-1);
    Capacity = capacity;
    return Capacity;
}

//Function for Constructor getUnoccupied
int ParkingLot::getUnoccupied(){

    for(int i=0;i<slotsDetails.size();i++){
        if(slotsDetails[i].getStatus()==-1) return i;
    }
    return -1;

}

//Function for Constructor parkCar
int ParkingLot::parkCar(string Regno, int age){


    if (TotalOccupiedSpace < Capacity) {
        int id = getUnoccupied();
        if(id <0) return -1;

        for(int i=0;i<slotsDetails.size();i++){
            if(slotsDetails[i].getRegNo() == Regno){
                return -2;
            }
        }

        slotsDetails[id].setStatus(1);
        slotsDetails[id].setRegNo(Regno);
        slotsDetails[id].setAge(age);

        ParkingId = ParkingId + 1;
        TotalOccupiedSpace = TotalOccupiedSpace + 1;

        return id + 1;

    }
    else
        return -1;
}

//Function for Constructor leave
pair<string,int> ParkingLot::leave(int ParkingId){

    if(ParkingId>Capacity || ParkingId == 0){
        return make_pair("-2",-1);
    }

    if(TotalOccupiedSpace>0 && slotsDetails[ParkingId-1].getStatus()!=-1 ){
        string regno = slotsDetails[ParkingId-1].getRegNo();
        int age = slotsDetails[ParkingId-1].getAge();
        slotsDetails[ParkingId-1].setStatus(-1);
        TotalOccupiedSpace = TotalOccupiedSpace - 1;
        return make_pair(regno, age);
    }

    return make_pair("-1",-1);
}


//Function for Constructor getRegNoFromAge
vector <string> ParkingLot::getRegNoFromAge(int age){

    vector<string > resultRegNoFromAge;


    for(int i=0;i<slotsDetails.size();i++){
        if(slotsDetails[i].getAge() == age){
            resultRegNoFromAge.push_back(slotsDetails[i].getRegNo());
        }
    }

    return resultRegNoFromAge;
}


//Function for Constructor getSlotNoFromRegNo
int ParkingLot::getSlotNoFromRegNo(string Regno){

    for(int i=0;i<slotsDetails.size();i++){
        if( slotsDetails[i].getRegNo() == Regno && slotsDetails[i].getStatus() == 1)
            return i+1;
    }

    return -1;
}


//Function for Constructor getSlotNoFromAge
vector<int> ParkingLot::getSlotNoFromAge(int age){

    vector< int > resultSlotNoFromAge;

    for(int i=0;i<slotsDetails.size();i++){
        if(slotsDetails[i].getAge() == age && slotsDetails[i].getStatus() == 1){
            resultSlotNoFromAge.push_back(i+1);
        }
    }

    return resultSlotNoFromAge;
}
