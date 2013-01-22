/* 
 * File:   Genetic.cpp
 * Author: asiron
 * 
 * Created on January 19, 2013, 1:48 PM
 */

#include "Genetic.h"

//#define DEBUG_GENETIC

Genetic::Genetic(Graph* graph, int epochs, float crossoverRate, float mutationRate, int populationSize, int eliteSize) {
    this->graph = graph;
    this->epochs = epochs;
    this->crossoverRate = crossoverRate;
    this->mutationRate = mutationRate;
    this->populationSize = populationSize;
    this->eliteSize = eliteSize;
    comp = new CompareGenome(DESC);
    population = new vector<Genome*>;
    for(int i=0; i<populationSize; ++i)
        population->push_back(new Genome(graph));
    sort(population->begin(), population->end(),*comp);
}

Genetic::Genetic(const Genetic& orig) {
    this->graph = orig.graph;
    this->epochs = orig.epochs;
    this->crossoverRate = orig.crossoverRate;
    this->mutationRate = orig.mutationRate;
    this->populationSize = orig.populationSize;
    this->eliteSize = orig.eliteSize;
    comp = orig.comp;
    result = orig.result;
    population = new vector<Genome*>(*(orig.population));
}

Genetic::~Genetic() {
    delete comp;
//    if(population){
//        for(vector<Genome*>::iterator it=population->begin(); it!=population->end(); it++){
//        delete *it;
//        }
//        delete population;
//    }
}


Genome& Genetic::run(){
    for(int i=0; i<epochs; ++i){
        vector<Genome*> *newPopulation = new vector<Genome*>;
        for(int j=0; j<eliteSize; ++j){
            newPopulation->push_back(population->back());
            population->pop_back();
        }
        sort(newPopulation->begin(), newPopulation->end(), *comp);
#ifdef DEBUG_GENETIC
        for(vector<Genome*>::iterator it=population->begin(); it != population->end(); it++){
            cout << (*it)->evaluate() << endl;
        }
        cout << "???" << endl;
        for(vector<Genome*>::iterator it=newPopulation->begin(); it != newPopulation->end(); it++){
            cout << (*it)->evaluate() << endl;
        }
#endif
        for(int j=0; j<populationSize-eliteSize; ++j){
            Genome *parent = new Genome(*population->back());
            if ( rand() / RAND_MAX < mutationRate ){
                parent->mutate();
            }
            if ( rand() / RAND_MAX < crossoverRate ){
                parent->crossover(*newPopulation->back());
            }
            //newPopulation->push_back(parent);
            newPopulation->insert(newPopulation->begin(), parent);
            population->pop_back();
        }
        sort(newPopulation->begin(), newPopulation->end(), *comp);
        population = newPopulation;
    }
    result = *population->back();
    return result;
}
