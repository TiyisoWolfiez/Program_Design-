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
GA::GA(GA* geneticAlgorithm){
    this->population=NULL;
    this->populationSize = 0;
    this->selectionSize = 0;
    if(geneticAlgorithm!=NULL){
        const int length_Array = geneticAlgorithm->populationSize;
        this->populationSize = geneticAlgorithm->populationSize;
        this->selectionSize = geneticAlgorithm->selectionSize;
        this->population = new Chromosome*[length_Array];
        for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
            this->population[k_iterator]=new Chromosome(geneticAlgorithm->population[k_iterator]);
        }
    }
}
GA::~GA(){
    const int length_Array = this->populationSize;
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        population[k_iterator] = NULL;
        delete population[k_iterator];
    }
    population = NULL;
    delete [] population;
    this->populationSize=0;
    this->selectionSize=0;
}
double** GA::run(FitnessFunction* fitnessFunction, int numGenerations){
    double **results = new double*[numGenerations];
    for(int t_iterator=0;t_iterator<numGenerations;t_iterator++){
        results[t_iterator] = new double[3];
    }
    for(int t_iterator=0;t_iterator<numGenerations;t_iterator++){
        this->setPopulation(this->run(fitnessFunction));
        results[t_iterator][0]=this->calculateAvgAccuracy(fitnessFunction);
        results[t_iterator][1]=this->calculateStd(fitnessFunction);
        results[t_iterator][2]=this->calculateVariance();
    }
    return results;
}
