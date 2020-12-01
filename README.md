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
Here are the steps to install C++ Compiler.

### Ubuntu
Here are the steps to install C++ Compiler


Use the package manager [pip](https://pip.pypa.io/en/stable/) to install the foobar.

```bash
pip install foobar
```

## Usage

```python
import foobar

foobar.pluralize('word') # returns 'words'
foobar.pluralize('goose') # returns 'geese'
foobar.singularize('phenomena') # returns 'phenomenon'
```
