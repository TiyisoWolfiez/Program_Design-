//Exception implementations
#include "Exceptions.h"
using namespace std;

AboveWeightEx::AboveWeightEx(double weight){
    AboveWeightEx::weightDiff = weight;
}
double AboveWeightEx::getDifference() const{
    return AboveWeightEx::weightDiff;
}

template <class E>
NotFoundEx<E>::NotFoundEx(E* miss){
    NotFoundEx<E>::missing = miss;
}
