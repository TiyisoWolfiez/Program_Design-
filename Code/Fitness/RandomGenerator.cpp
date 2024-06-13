#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed){
    srand(seed);
    this->seed = seed;
}
