//The Passenger implementation file
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string ID, double weight, double ticketPrice){
    Passenger::ID = ID;;
    Passenger::weight = weight;
    Passenger::ticketPrice = ticketPrice;
}
double Passenger::getWeight() const{
    return Passenger::weight;
}
double Passenger::getValue() const{
    return Passenger::ticketPrice;
}
