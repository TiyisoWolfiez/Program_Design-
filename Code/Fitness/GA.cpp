#include "GA.h"

GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize){
    this->populationSize = populationSize;
    this->selectionSize = selectionSize;
    const int length_Array = this->populationSize;
    this->population = new Chromosome*[length_Array];
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        this->population[k_iterator]=new Chromosome(numGenes, rand);
    }
}
