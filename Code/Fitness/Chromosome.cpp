#include "Chromosome.h"

Chromosome::Chromosome(int numGenes, RandomGenerator* rand){
    if(numGenes<0){ this->numGenes = 0;}
    else{ this->numGenes = numGenes;}
    this->genes = new bool[this->numGenes];
    if(rand == NULL){
        for(int k_iterator=0;k_iterator<this->numGenes;k_iterator++){
            genes[k_iterator]=false;
        }
    }
    else{
        for(int k_iterator=0;k_iterator<this->numGenes;k_iterator++){
            genes[k_iterator]=rand->randomBool();
        }
    }
}
