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
Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2){
    Chromosome** crossOverPopulation = new Chromosome*[2];
    crossOverPopulation[0] = new Chromosome(c1->crossOver(c2));
    crossOverPopulation[1] = new Chromosome(c2->crossOver(c1));
    return crossOverPopulation;
}
Chromosome* GA::mutate(Chromosome* c1){
    return c1->mutate();
}
double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction){
    double avgAccuracy = 0;
    const int length_Array = this->populationSize;
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        if(this->population[k_iterator]!=NULL){
            avgAccuracy+=this->population[k_iterator]->fitness(fitnessFunction, this->population[k_iterator], this->population[k_iterator]->getNumGenes());
        }
    }
    return avgAccuracy/length_Array;
}
double GA::calculateStd(FitnessFunction* fitnessFunction){
    double avgAccuracy = calculateAvgAccuracy(fitnessFunction), stdAccuracy = 0;
    const int length_Array = this->populationSize;
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        if(this->population[k_iterator]!=NULL){
            double fitnesP = this->population[k_iterator]->fitness(fitnessFunction, this->population[k_iterator], this->population[k_iterator]->getNumGenes());
            stdAccuracy+=pow((fitnesP-avgAccuracy),2);
        }
    }
    return sqrt(stdAccuracy/length_Array);
}
double GA::calculateVariance(){
    double numUnique = 0;
    const int length_Array = this->populationSize;
    std::string *myArray = new std::string[length_Array];
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        myArray[k_iterator]="X";
    }
    int index = 0;
    std::string myTempString;
    for(int t_iterator=0;t_iterator<length_Array;t_iterator++){
        if(this->population[t_iterator]!=NULL){
            myTempString=this->population[t_iterator]->toString();
            myTempString+=this->population[t_iterator]->getNumGenes();
        }
        bool found = false;
        for(int t_iterator=0;t_iterator<length_Array;t_iterator++){
            if(myArray[t_iterator]==myTempString){
                found = true;
                break;
            }
        }
        if(found==false){
            myArray[index] = myTempString;
            index+=1;
        }
    }
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        if(myArray[k_iterator]!="X"){
            numUnique+=1;
        }
    }
    delete [] myArray;
    myArray = NULL;
    return numUnique/length_Array;
}
void GA::setPopulation(Chromosome** geneticAlgorithm){
    const int length_Array = this->populationSize;
    this->population = new Chromosome*[length_Array];
    for(int k_iterator=0;k_iterator<length_Array;k_iterator++){
        if(geneticAlgorithm[k_iterator]!=NULL){
            this->population[k_iterator]=new Chromosome(geneticAlgorithm[k_iterator]->getGenes(),geneticAlgorithm[k_iterator]->getNumGenes());
        }
    }
}    
