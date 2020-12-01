# Parking Lot Design

# Dependencies

C++ that's it.


# Description
We own a parking lot that can hold up to ‘n’ cars at any given point in time. Each slot is given a number starting at one increasing with increasing distance from the entry point in steps of one. We want to create an automated ticketing system that allows our customers to use our parking lot without human intervention.

When a car enters the parking lot, we want to have a ticket issued to the driver. The ticket issuing process includes:-

We are taking note of the number written on the vehicle registration plate and the age of the driver of the car.

And we are allocating an available parking slot to the car before actually handing over a ticket to the driver (we assume that our customers are kind enough to always park in the slots allocated to them).

The customer should be allocated a parking slot that is nearest to the entry. At the exit, the customer returns the ticket, marking the slot they were using as being available.

Due to government regulation, the system should provide us with the ability to find out:-

Vehicle Registration numbers for all cars which are parked by the driver of a certain age,
Slot number in which a car with a given vehicle registration plate is parked.
Slot numbers of all slots where cars of drivers of a particular age are parked.
We interact with the system via a file-based input system, i.e. it should accept a filename as an input. The file referenced by filename will contain a set of commands separated by a newline, we need to execute the commands in order and produce output.



## Setup Instructions

### Mac

Here are the steps to setup c++ environment:

Step 1: Open the App Store

Step 2: Search for Xcode

Step 3: Install Xcode

Step 4: Launch Xcode


### Ubuntu

Step to install C++ environment:

Open a new terminal window and type the following command and press enter:

```sudo apt-get install g++```






### Steps to run the program on Mac:



##### Step 1: Open a new terminal window.

##### Step 2 − Change the directory to the directory in which you have `TakeHomeActivity.cpp` file. 

For example, if it is in Downloads/Parking_Lot_Sytem-main, enter your command line −


$ cd Downloads/Parking_Lot_Sytem-main

![](Path.JPG)


##### Step 3 − Now enter the following command to compile the source file using g++.

$ g++ -o [Name that you want to give] TakeHomeActivity.cpp.cpp

In place of [Name that you want to give] replace it by any name like myprogram, etc.

![](compile.JPG)

##### Step 4 − Run it! Now you can run the program using −

$ ./myprogram


![](execution.JPG)



## TestCase:

#### Input File contains the input. In order to test the program, put your test case in the input file

Here is the formal for input: 

```
Create_parking_lot 6
Park KA-01-HH-1234 driver_age 21
Park PB-01-HH-1234 driver_age 21
Slot_numbers_for_driver_of_age 21
Park PB-01-TG-2341 driver_age 40
Slot_number_for_car_with_number PB-01-HH-1234
Leave 2
Park HR-29-TG-3098 driver_age 39
Vehicle_registration_number_for_driver_of_age 18
```

#### Output File contains the output. Your output will be stored in the output file. 

Here is the format of output file:

```Creating Parking of 6 slots
Car with vehicle registration number KA-01-HH-1234 with having driver's age of : 21 has been parked at slot number 1
Car with vehicle registration number PB-01-HH-1234 with having driver's age of : 21 has been parked at slot number 2
1.) 1   2.) 2   
Car with vehicle registration number PB-01-TG-2341 with having driver's age of : 40 has been parked at slot number 3
2
Slot Number : 2 vacated, the car with vehicle registration number :PB-01-HH-1234 left the space.
Car with vehicle registration number HR-29-TG-3098 with having driver's age of : 39 has been parked at slot number 2
NO Car is present

```
