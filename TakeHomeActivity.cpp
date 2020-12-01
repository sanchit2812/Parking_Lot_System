#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "ParkingLot.h"

using namespace std;


// Function to convert string to int
int convert(string s){
    int x=0;
    for(int i=0;i<s.size();i++){
        x = 10*x + (s[i]-'0');
    }
    return x;
}


int main(){

    string s;
    ifstream myfile ("input.txt"); // Input.txt is the file for input
    ofstream minefile ("output.txt"); // In output.txt, the output will be stored


    if (myfile.is_open()){
        Parking_Lot obj; // Creation of an object of class Parking_Lot

        while ( getline (myfile,s) ){ // getting input till there is a line to take input

            istringstream ss(s);

            // Dividing the whole string by spaces
            string word;
            vector<string> v;// vector v contains the words
            while (ss >> word) v.push_back(word);

            // Case: when Create_parking_lot is called
            if(v[0] == "Create_parking_lot"){

                int x = convert(v[1]);
                obj.Capacity = x;
                int cnt = obj.createParkingLot(x);
                minefile << "Creating Parking of "<<cnt<<" slots"<<endl;
            }

            // Case: when Park is called
            else if(v[0] == "Park"){


                int ag = convert(v[3]);
                int slot_booked = obj.parkCar(v[1],ag);
                if(slot_booked == -2) minefile<<"This car has already present in the parking."<<endl;
                else if(slot_booked == -1) minefile <<"Parking FULL"<<endl;
                else minefile <<"Car with vehicle registration number "<< v[1] <<" with having driver's age of : "<<v[3]<<" has been parked at slot number "<<slot_booked<<endl;
            }


            // Case: when Car is going to Leave
            else if(v[0] == "Leave"){


                pair<string, int> car_info = obj.leave(convert(v[1]));
                if(car_info.first == "-2") minefile<<"Slot is not available in this parking area"<<endl;
                else if(car_info.first == "-1") minefile <<"Slot is already vacant"<<endl;
                else{
                    minefile <<"Slot Number : "<<convert(v[1])<<" vacated, the car with vehicle registration number :"<<car_info.first<<" left the space."<<endl;
                }
            }


            // Case: when Vehicle registration number required for driver of given age
            else if(v[0] == "Vehicle_registration_number_for_driver_of_age"){

                vector<string> vec = obj.getRegNoFromAge(convert(v[1]));
                if(vec.size()==0){
                    minefile <<"NO Car is present"<<endl;
                }
                else{
                    for(int i=0;i<vec.size();i++) minefile <<i+1<<".) "<<vec[i]<<"    ";
                    minefile <<endl;
                }
            }

            // Case: when Slot numbers is required for driver of given age
            else if(v[0] == "Slot_numbers_for_driver_of_age"){

                vector<int> vec = obj.getSlotNoFromAge(convert(v[1]));
                if(vec.size()==0){
                    minefile <<"NO Car is present"<<endl;
                }
                else{
                    for(int i=0;i<vec.size();i++) minefile <<i+1<<".) "<<vec[i]<<"   ";
                    minefile <<endl;
                }
            }


            // Case: when Slot number is required for Car from given registration number
            else if(v[0] == "Slot_number_for_car_with_number"){

                int slotno = obj.getSlotNoFromRegNo(v[1]);

                if(slotno == -1) minefile <<"Not Found"<<endl;
                else minefile <<slotno<<endl;
            }
        }

        myfile.close(); // input file is closed
    }

    else minefile  << "Unable to open file"<<endl; // case when the file is unable to open

    minefile.close(); // output file is closed


    return 0;
}
