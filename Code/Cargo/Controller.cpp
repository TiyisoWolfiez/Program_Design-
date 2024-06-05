// The Controller implementation file
#include "Controller.h"
using namespace std;

template <class T>
Controller<T>::Controller(Plane<T>* plane){
    Controller<T>::plane = plane;
}
template <class T>
string Controller<T>::loadOnPlane(T* var){
    try{
        Controller<T>::plane->add(var);
        return "Success";
    }
    catch(AboveWeightEx exception){
        std::string temp(""), temp1 = "Could not load item, above max weight by ";
        double temp2 = (exception.getDifference());
        std::stringstream ss;
        ss << temp2;
        ss >> temp;
        return "Could not load item, above max weight by " + temp;
    }
}
