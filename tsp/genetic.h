#ifndef GENETIC_H
#define	GENETIC_H

#include <cstdlib>
#include <queue>
#include <algorithm>
#include "graph.h"
#include "Genome.h"

using namespace std;

class Genome;
class CompareGenome;

class Genetic {
public:
    Genetic(Graph* graph, int epochs, float crossoverRate, float mutationRate, int populationSize, int eliteSize);
    Genetic(const Genetic& orig);
    ~Genetic();
    
    Genome& run();
    
    int firstPopulation(){
        return this->population->back()->evaluate();
    }
private:
    float       mutationRate;
    float       crossoverRate;
    int         populationSize;
    int         eliteSize;
    int         epochs;
    Graph       *graph;
    vector<Genome*>      *population;
    Genome      result;
    CompareGenome *comp;
    
};
#endif	/* GENETIC_H */

