#include <iostream>
#include <vector>
using namespace std;

#include "CarDriver.h"

// Class declaration for Parking_Lot
class Parking_Lot{

    public:
        int Capacity = 0;
        int Parking_Id =0;
        int Total_Occupied_Space =0;

        vector<CarDriver> abc;// vector initialization for derived class

        int createParkingLot(int capacity); // Constructor initialization for createParkingLot
        int getUnoccupied();//Constructor initialization for getUnoccupied
        int parkCar(string Reg_no, int age);//Constructor initialization for parkCar
        pair<string,int> leave(int Parking_Id);//Constructor initialization for leave
        vector <string> getRegNoFromAge(int age);//Constructor initialization for getRegNoFromAge
        int getSlotNoFromRegNo(string Reg_no);//Constructor initialization for getSlotNoFromRegNo
        vector<int> getSlotNoFromAge(int age);//Constructor initialization for getSlotNoFromAge

};

//Function for Constructor createParkingLot
int Parking_Lot::createParkingLot(int capacity){

    abc.resize(capacity);

    for(int i=0;i<capacity;i++) abc[i].setNum(-1);
    Capacity = capacity;
    return Capacity;
}

//Function for Constructor getUnoccupied
int Parking_Lot::getUnoccupied(){

    int i=0;

    for(i=0;i<abc.size();i++){
        if(abc[i].getNum()==-1) return i;
    }
    return -1;

}

//Function for Constructor parkCar
int Parking_Lot::parkCar(string Reg_no, int age){


    if (Total_Occupied_Space < Capacity) {
        int id = getUnoccupied();
        if(id <0) return -1;

        for(int i=0;i<abc.size();i++){
            if(abc[i].getRegNo() == Reg_no){
                return -2;
            }
        }

        abc[id].setNum(1);
        abc[id].setRegNo(Reg_no);
        abc[id].setAge(age);

        Parking_Id = Parking_Id + 1;
        Total_Occupied_Space = Total_Occupied_Space + 1;

        return id + 1;

    }
    else
        return -1;
}

//Function for Constructor leave
pair<string,int> Parking_Lot::leave(int Parking_Id){

    if(Parking_Id>Capacity || Parking_Id == 0){
        return make_pair("-2",-1);
    }

    if(Total_Occupied_Space>0 && abc[Parking_Id-1].getNum()!=-1 ){
        string regno = abc[Parking_Id-1].getRegNo();
        int age = abc[Parking_Id-1].getAge();
        abc[Parking_Id-1].setNum(-1);
        Total_Occupied_Space = Total_Occupied_Space - 1;
        return make_pair(regno, age);
    }

    return make_pair("-1",-1);
}


//Function for Constructor getRegNoFromAge
vector <string> Parking_Lot::getRegNoFromAge(int age){

    vector<string > ans;


    for(int i=0;i<abc.size();i++){
        if(abc[i].getAge() == age){
            ans.push_back(abc[i].getRegNo());
        }
    }

    return ans;
}


//Function for Constructor getSlotNoFromRegNo
int Parking_Lot::getSlotNoFromRegNo(string Reg_no){

    for(int i=0;i<abc.size();i++){
        if( abc[i].getRegNo() == Reg_no && abc[i].getNum() == 1)
            return i+1;
    }

    return -1;
}


//Function for Constructor getSlotNoFromAge
vector<int> Parking_Lot::getSlotNoFromAge(int age){

    vector< int > ans;

    for(int i=0;i<abc.size();i++){
        if(abc[i].getAge() == age && abc[i].getNum() == 1){
            ans.push_back(i+1);
        }
    }

    return ans;
}
