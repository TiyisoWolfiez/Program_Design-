// The Plane implementation file
#include "Plane.h"
using namespace std;

template <class T>
Plane<T>::Plane(double maxWeight){
    Plane<T>::maxWeight = maxWeight;
}
template <class T>
void Plane<T>::remove(T* var){
    bool found = false;
    int index = -1*Plane<T>::cargo.size();
    if(Plane<T>::cargo.empty() == !false){
        throw EmptyEx();
    }
    for(int i=0, n = Plane<T>::cargo.size(); i< n; i++){
        if(Plane<T>::cargo[i]==var){
            index = i;
            found = true;
            break;
        }
    }
    if(found == false){
        throw NotFoundEx<T>(var);
    }
    else{
        Plane<T>::cargo.erase(Plane<T>::cargo.begin() + index);
    }
}
template <class T>
string Plane<T>::getDescription(){
    if(Plane<T>::cargo.empty() == !false){
        throw EmptyEx();
    }
    else{
        string returned = "";
        for(int k=0, n = Plane<T>::cargo.size(); k< n; k++){
            if(Plane<T>::cargo[k]){
                returned += Plane<T>::cargo[k]->describe() + "\n";
            }
        }
        int len = returned.length()-1;
        return returned.substr(len-(returned.length()-1), len);
    }
    return "";
}
