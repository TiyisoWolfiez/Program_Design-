//The Cargo implementation file
#include "Cargo.h"
using namespace std;

class Cargo
{
    private:
        double weight;
        double value;
    public:
        Cargo(double weight, double value);
        double getWeight() const;
        double getValue() const;
        std::string describe();
};
#endif
