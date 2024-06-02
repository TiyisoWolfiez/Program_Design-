#ifndef Exception_H
#define Exception_H
#include <sstream>

template <class E>
class UndervaluedEx{
    private:
        E* underVal;
        double sum;
    public:
        UndervaluedEx(E* UnderVal1, double sum);
        E* getUndervalued() const;
        double getSum() const;
};
template <class E>
class NotFoundEx{
    private:
        E* missing;
    public:
        NotFoundEx(E* mising1);
        E* getNotFound() const;
};
